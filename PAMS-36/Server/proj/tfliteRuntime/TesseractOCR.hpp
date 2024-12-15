#ifndef TESSERACTOCR_HPP
#define TESSERACTOCR_HPP

#include <string>
#include <opencv2/opencv.hpp>
#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>

class TesseractOCR {
public:
    TesseractOCR();
    ~TesseractOCR();

    std::string performOCR(cv::Mat& image);

private:
    tesseract::TessBaseAPI ocr;
};

#endif // TESSERACTOCR_HPP

