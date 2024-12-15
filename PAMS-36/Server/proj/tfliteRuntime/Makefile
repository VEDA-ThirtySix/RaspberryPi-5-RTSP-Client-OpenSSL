# Makefile
CXX = g++
CXXFLAGS = -std=c++17 -Wall -O2 `pkg-config --cflags opencv4 tesseract`
LDFLAGS = -ltensorflow-lite `pkg-config --libs opencv4 tesseract`

SRC = main.cpp YuvHandler.cpp TesseractOCR.cpp AlignmentModel.cpp
OBJ = $(SRC:.cpp=.o)
TARGET = tfliteRuntime

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)

