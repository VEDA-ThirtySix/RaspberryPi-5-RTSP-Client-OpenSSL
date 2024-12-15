#include <tensorflow/lite/interpreter.h>
#include <tensorflow/lite/kernels/register.h>
#include <tensorflow/lite/model.h>
#include <vector>
#include <stdexcept>
#include <fstream>
#include <cstdint>
#include <cmath>
#include <cstring>

class DHDetectionModel {
private:
    const std::string model_name = "yolov5.tflite";
    const int batch_size = 1;
    const int img_height = 192;
    const int img_width = 256;
    const int num_channel = 3;

    std::unique_ptr<tflite::FlatBufferModel> model;
    std::unique_ptr<tflite::Interpreter> interpreter;
    std::vector<float> detection_result;

public:
    DHDetectionModel(const std::string& model_path) {
        // Load model
        model = tflite::FlatBufferModel::BuildFromFile(model_path.c_str());
        if (!model) {
            throw std::runtime_error("Failed to load model: " + model_path);
        }

        // Build interpreter
        tflite::InterpreterBuilder(*model, tflite::ops::builtin::BuiltinOpResolver())(&interpreter);
        if (!interpreter) {
            throw std::runtime_error("Failed to create interpreter");
        }

        // Allocate tensors
        if (interpreter->AllocateTensors() != kTfLiteOk) {
            throw std::runtime_error("Failed to allocate tensors");
        }

        // Prepare result buffer
        detection_result.resize(interpreter->output_tensor(0)->bytes / sizeof(float));
    }

    void preprocess(const uint8_t* input_image, int original_width, int original_height, int channels) {
        auto* input_tensor = interpreter->typed_tensor<float>(interpreter->inputs()[0]);

        // Resize and normalize image data manually
        float scale_w = static_cast<float>(img_width) / original_width;
        float scale_h = static_cast<float>(img_height) / original_height;

        for (int y = 0; y < img_height; ++y) {
            for (int x = 0; x < img_width; ++x) {
                // Map target (x, y) to source coordinates
                int src_x = static_cast<int>(x / scale_w);
                int src_y = static_cast<int>(y / scale_h);
                int src_index = (src_y * original_width + src_x) * channels;

                // Read RGB values
                float r = input_image[src_index] / 255.0f;
                float g = input_image[src_index + 1] / 255.0f;
                float b = input_image[src_index + 2] / 255.0f;

                // Write normalized values to input tensor
                int target_index = (y * img_width + x) * num_channel;
                input_tensor[target_index] = r;
                input_tensor[target_index + 1] = g;
                input_tensor[target_index + 2] = b;
            }
        }
    }

    std::vector<float> run(const uint8_t* input_image, int original_width, int original_height, int channels) {
        preprocess(input_image, original_width, original_height, channels);

        if (interpreter->Invoke() != kTfLiteOk) {
            throw std::runtime_error("Failed to invoke interpreter");
        }

        float* output_data = interpreter->typed_output_tensor<float>(0);
        std::copy(output_data, output_data + detection_result.size(), detection_result.begin());

        return detection_result;
    }

    std::vector<float> getProposal(const uint8_t* input_image, int original_width, int original_height, int channels) {
        auto detections = run(input_image, original_width, original_height, channels);
        float max_conf = detections[4];
        int idx = 0;

        for (size_t i = 1; i < detections.size() / 6; ++i) {
            if (detections[i * 6 + 4] > max_conf) {
                max_conf = detections[i * 6 + 4];
                idx = i;
            }
        }

        float x1 = detections[idx * 6 + 0] * 256 - detections[idx * 6 + 2] * 128;
        float y1 = detections[idx * 6 + 1] * 192 - detections[idx * 6 + 3] * 96;
        float x2 = detections[idx * 6 + 0] * 256 + detections[idx * 6 + 2] * 128;
        float y2 = detections[idx * 6 + 1] * 192 + detections[idx * 6 + 3] * 96;

        float gain_w = 256.0f / original_width;
        float gain_h = 192.0f / original_height;

        x1 = (x1 / gain_w);
        y1 = (y1 / gain_h);
        x2 = (x2 / gain_w);
        y2 = (y2 / gain_h);

        float x_c = (x1 + x2) / 2.0f;
        float y_c = (y1 + y2) / 2.0f;
        float w = x2 - x1;
        float h = y2 - y1;

        return {x_c / original_width, y_c / original_height, w / original_width, h / original_height, max_conf};
    }
};

