#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
#include <filesystem>
#include <chrono>
#include <thread>
#include <algorithm>
#include <opencv2/opencv.hpp>
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include "ObjectDetectionModel.h"

namespace fs = std::filesystem;

class AlignmentModel {
public:
    AlignmentModel(const std::string& model_path)
        : mModel(tflite::FlatBufferModel::BuildFromFile(model_path.c_str())) {
        if (!mModel) {
            throw std::runtime_error("Failed to load model file: " + model_path);
        }

        tflite::ops::builtin::BuiltinOpResolver resolver;
        tflite::InterpreterBuilder(*mModel, resolver)(&mInterpreter);
        if (!mInterpreter) {
            throw std::runtime_error("Failed to create TFLite interpreter.");
        }

        if (mInterpreter->AllocateTensors() != kTfLiteOk) {
            throw std::runtime_error("Failed to allocate tensors.");
        }

        mInputTensor = mInterpreter->tensor(mInterpreter->inputs()[0]);
        if (mInputTensor->type != kTfLiteFloat32) {
            throw std::runtime_error("Expected input tensor type to be float32.");
        }
    }

    std::vector<float> getCoordinate(const cv::Mat& image) {
        preprocessImage(image);

        if (mInterpreter->Invoke() != kTfLiteOk) {
            throw std::runtime_error("Failed to invoke TFLite interpreter.");
        }

        auto* outputTensor = mInterpreter->tensor(mInterpreter->outputs()[0]);
        std::vector<float> detectionResult(outputTensor->data.f,
                                           outputTensor->data.f + outputTensor->dims->data[1]);
        return detectionResult;
    }

private:
    void preprocessImage(const cv::Mat& image) {
        if (image.empty() || image.cols != IMG_WIDTH || image.rows != IMG_HEIGHT) {
            throw std::invalid_argument("Image size must be " + std::to_string(IMG_WIDTH) + "x" + std::to_string(IMG_HEIGHT));
        }

        float* inputBuffer = mInputTensor->data.f;
        for (int i = 0; i < IMG_HEIGHT; ++i) {
            for (int j = 0; j < IMG_WIDTH; ++j) {
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
                *inputBuffer++ = pixel[2] / 255.0f; // Red
            }
        }
        for (int i = 0; i < IMG_HEIGHT; ++i) {
            for (int j = 0; j < IMG_WIDTH; ++j) {
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
                *inputBuffer++ = pixel[1] / 255.0f; // Green
            }
        }
        for (int i = 0; i < IMG_HEIGHT; ++i) {
            for (int j = 0; j < IMG_WIDTH; ++j) {
                cv::Vec3b pixel = image.at<cv::Vec3b>(i, j);
                *inputBuffer++ = pixel[0] / 255.0f; // Blue
            }
        }
    }

    std::unique_ptr<tflite::FlatBufferModel> mModel;
    std::unique_ptr<tflite::Interpreter> mInterpreter;
    TfLiteTensor* mInputTensor;

    static constexpr int IMG_WIDTH = 128;
    static constexpr int IMG_HEIGHT = 128;
};

bool isFileReady(const fs::path& path) {
    std::error_code ec;
    auto fileSize = fs::file_size(path, ec);
    if (ec) return false;

    // 예상되는 YUV 파일 크기 (800x600 YUV420 형식)
    const uintmax_t expectedSize = 800 * 600 * 3 / 2;
    return fileSize == expectedSize;
}

std::string performOCR(cv::Mat& image) {
    tesseract::TessBaseAPI ocr;
    if (ocr.Init(NULL, "kor")) {
        throw std::runtime_error("Could not initialize Tesseract.");
    }

    ocr.SetVariable("tessedit_char_whitelist", "0123456789가나다");
    ocr.SetImage(image.data, image.cols, image.rows, 3, image.step);

    ocr.Recognize(0);
    tesseract::ResultIterator* ri = ocr.GetIterator();
    tesseract::PageIteratorLevel level = tesseract::RIL_SYMBOL;

    std::string detectedText;
    if (ri != nullptr) {
        do {
            const char* symbol = ri->GetUTF8Text(level);
            if (symbol != nullptr && ri->Confidence(level) >= 70) {
                detectedText += symbol;
            }
            delete[] symbol;
        } while (ri->Next(level));
    }

    ocr.End();
    return detectedText;
}

void processYUVFile(const fs::path& yuv_file, DHDetectionModel& detectionModel, AlignmentModel& alignmentModel, const std::string& save_dir) {
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

        std::string detectedText = performOCR(outputImage);
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

void monitorDetectYUV(const std::string& watch_dir, const std::string& save_dir, const std::string& detect_model_path, const std::string& align_model_path) {
    DHDetectionModel detectionModel(detect_model_path);
    AlignmentModel alignmentModel(align_model_path);

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
                processYUVFile(yuv_file, detectionModel, alignmentModel, save_dir);
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(1));
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
}

int main() {
    const std::string watch_dir = "../tmp";
    const std::string save_dir = "../ANPR";
    const std::string detect_model_path = "../tflite/yolov5.tflite";
    const std::string align_model_path = "../tflite/align.tflite";

    try {
        if (!fs::exists(save_dir)) {
            fs::create_directories(save_dir);
        }

        monitorDetectYUV(watch_dir, save_dir, detect_model_path, align_model_path);
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

