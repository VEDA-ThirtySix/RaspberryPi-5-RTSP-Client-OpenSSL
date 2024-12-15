#!/bin/bash

# 패키지 목록
packages=(
    tesseract-ocr-kor
    libopencv-dev
    tesseract-ocr
    libtesseract-dev
    libavcodec-dev
    libavformat-dev
    libavutil-dev
    libswscale-dev
    libjson-c-dev
    libsqlite3-dev
    libssl-dev
    libsrtp2-dev
)

# 각 패키지 설치 여부 확인 및 설치
for package in "${packages[@]}"
do
    if ! dpkg -l | grep -q "^ii  $package"; then
        echo "Installing $package..."
        sudo apt update
        sudo apt install -y "$package"
    else
        echo "$package is already installed."
    fi
done

# TensorFlow Lite deb 파일 설치
deb_file="tflite/tensorflow-lite_64.deb"

if [ -f "$deb_file" ]; then
    echo "Found $deb_file. Installing..."
    sudo apt install -y ./"$deb_file"
else
    echo "Error: $deb_file not found. Please ensure the file exists in the 'tflite' directory."
fi

# b64.c 설치 확인

echo "Setup completed."

