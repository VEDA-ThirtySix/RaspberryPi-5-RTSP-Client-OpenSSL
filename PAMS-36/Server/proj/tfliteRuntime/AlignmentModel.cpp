#include "AlignmentModel.hpp"
#include <stdexcept>
#include <opencv2/opencv.hpp>
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>

AlignmentModel::AlignmentModel(const std::string& model_path)
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

std::vector<float> AlignmentModel::getCoordinate(const cv::Mat& image) {
    preprocessImage(image);

    if (mInterpreter->Invoke() != kTfLiteOk) {
        throw std::runtime_error("Failed to invoke TFLite interpreter.");
    }

    auto* outputTensor = mInterpreter->tensor(mInterpreter->outputs()[0]);
    std::vector<float> detectionResult(outputTensor->data.f,
                                       outputTensor->data.f + outputTensor->dims->data[1]);
    return detectionResult;
}

void AlignmentModel::preprocessImage(const cv::Mat& image) {
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

