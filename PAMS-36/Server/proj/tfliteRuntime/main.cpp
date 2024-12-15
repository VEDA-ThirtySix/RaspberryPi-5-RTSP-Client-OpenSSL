#include "YuvHandler.hpp"
#include <iostream>
#include <filesystem>

int main() {
    const std::string watch_dir = "tmp";
    const std::string save_dir = "ANPR";
    const std::string detect_model_path = "tflite/yolov5.tflite";
    const std::string align_model_path = "tflite/align.tflite";

    try {
        if (!std::filesystem::exists(save_dir)) {
            std::filesystem::create_directories(save_dir);
        }

        YuvHandler handler(detect_model_path, align_model_path);
        handler.monitorDetectYUV(watch_dir, save_dir);
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }

    return 0;
}

