// AlignmentModel.hpp
#ifndef ALIGNMENTMODEL_HPP
#define ALIGNMENTMODEL_HPP

#include <opencv2/opencv.hpp>
#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

class AlignmentModel {
public:
    AlignmentModel(const std::string& model_path);
    std::vector<float> getCoordinate(const cv::Mat& image);

private:
    void preprocessImage(const cv::Mat& image);

    std::unique_ptr<tflite::FlatBufferModel> mModel;
    std::unique_ptr<tflite::Interpreter> mInterpreter;
    TfLiteTensor* mInputTensor;

    static constexpr int IMG_WIDTH = 128;
    static constexpr int IMG_HEIGHT = 128;
};

#endif // ALIGNMENTMODEL_HPP
