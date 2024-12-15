#include "YuvHandler.hpp"
#include <iostream>
#include <fstream>
#include <thread>
#include <algorithm>

YuvHandler::YuvHandler(const std::string& detect_model_path, const std::string& align_model_path)
    : detectionModel(detect_model_path), alignmentModel(align_model_path) {}

bool YuvHandler::isFileReady(const fs::path& path) {
    std::error_code ec;
    auto fileSize = fs::file_size(path, ec);
    return !ec && fileSize == 800 * 600 * 3 / 2;
}

void YuvHandler::processYUVFile(const fs::path& yuv_file, const std::string& save_dir) {
    if (!isFileReady(yuv_file)) {
        std::cout << "File not ready: " << yuv_file << std::endl;
        return;
    }

    std::vector<uint8_t> yuv_data;
    {
        std::ifstream file(yuv_file, std::ios::binary);
        if (!file.is_open()) {
            throw std::runtime_error("Failed to open " + yuv_file.string());
        }
        yuv_data.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    }

    int width = 800;
    int height = 600;
    cv::Mat yuv(height + height / 2, width, CV_8UC1, yuv_data.data());
    cv::Mat bgr;
    cv::cvtColor(yuv, bgr, cv::COLOR_YUV2BGR_I420);

    std::vector<float> result = detectionModel.getProposal(bgr.data, bgr.cols, bgr.rows, 3);

    if (result[4] >= 0.8) {
        int x1 = static_cast<int>((result[0] - result[2] / 2.0f) * bgr.cols);
        int y1 = static_cast<int>((result[1] - result[3] / 2.0f) * bgr.rows);
        int x2 = static_cast<int>((result[0] + result[2] / 2.0f) * bgr.cols);
        int y2 = static_cast<int>((result[1] + result[3] / 2.0f) * bgr.rows);

        x1 = std::max(0, std::min(x1, bgr.cols - 1));
        y1 = std::max(0, std::min(y1, bgr.rows - 1));
        x2 = std::max(0, std::min(x2, bgr.cols - 1));
        y2 = std::max(0, std::min(y2, bgr.rows - 1));

        cv::Mat roi = bgr(cv::Rect(x1, y1, x2 - x1, y2 - y1));
        cv::resize(roi, roi, cv::Size(128, 128));

        std::vector<float> coordinates = alignmentModel.getCoordinate(roi);

        for (auto& coord : coordinates) {
            coord = 1.0f / (1.0f + std::exp(-coord)) * 128;
        }

        std::vector<cv::Point2f> srcPoints = {
            {coordinates[0], coordinates[1]},
            {coordinates[2], coordinates[3]},
            {coordinates[4], coordinates[5]},
            {coordinates[6], coordinates[7]}
        };
        std::vector<cv::Point2f> dstPoints = {
            {0, 0}, {255, 0}, {255, 127}, {0, 127}
        };

        cv::Mat transformMatrix = cv::getPerspectiveTransform(srcPoints, dstPoints);
        cv::Mat outputImage;
        cv::warpPerspective(roi, outputImage, transformMatrix, cv::Size(256, 128), cv::INTER_CUBIC);

        std::string detectedText = ocr.performOCR(outputImage);
        if (detectedText.empty()) {
            detectedText = "unknown";
        }

        std::string output_path = save_dir + "/" + detectedText + ".jpg";
        if (!cv::imwrite(output_path, outputImage)) {
            throw std::runtime_error("Failed to save output image: " + output_path);
        }

        std::cout << "Aligned and saved plate image as " << output_path << std::endl;
    }

    fs::remove(yuv_file);
    std::cout << "Deleted processed file: " << yuv_file << std::endl;
}

void YuvHandler::monitorDetectYUV(const std::string& watch_dir, const std::string& save_dir) {
    while (true) {
        try {
            std::vector<fs::path> yuv_files;
            for (const auto& entry : fs::directory_iterator(watch_dir)) {
                if (entry.is_regular_file() && entry.path().extension() == ".yuv") {
                    yuv_files.push_back(entry.path());
                }
            }
            std::sort(yuv_files.begin(), yuv_files.end());
            for (const auto& yuv_file : yuv_files) {
                processYUVFile(yuv_file, save_dir);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

