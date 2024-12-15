#ifndef YUVHANDLER_HPP
#define YUVHANDLER_HPP

#include <filesystem>
#include <opencv2/opencv.hpp>
#include "AlignmentModel.hpp"
#include "TesseractOCR.hpp"
#include "ObjectDetectionModel.h"

namespace fs = std::filesystem;

class YuvHandler {
public:
    YuvHandler(const std::string& detect_model_path, const std::string& align_model_path);

    void monitorDetectYUV(const std::string& watch_dir, const std::string& save_dir);

private:
    bool isFileReady(const fs::path& path);
    void processYUVFile(const fs::path& yuv_file, const std::string& save_dir);

    DHDetectionModel detectionModel;
    AlignmentModel alignmentModel;
    TesseractOCR ocr;
};

#endif // YUVHANDLER_HPP

