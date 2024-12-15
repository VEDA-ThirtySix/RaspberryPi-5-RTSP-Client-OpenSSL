#include "TesseractOCR.hpp"

TesseractOCR::TesseractOCR() {
    if (ocr.Init(NULL, "kor")) {
        throw std::runtime_error("Could not initialize Tesseract.");
    }
    ocr.SetVariable("tessedit_char_whitelist", "0123456789가나다");
}

TesseractOCR::~TesseractOCR() {
    ocr.End();
}

std::string TesseractOCR::performOCR(cv::Mat& image) {
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
    return detectedText;
}

