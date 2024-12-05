#include "Image.hpp"
#include <fstream>
#include <stdexcept>
#include <cstring>

#pragma pack(push, 1)
struct BMPFileHeader {
    uint16_t fileType{0x4D42}; // BM
    uint32_t fileSize{0};
    uint16_t reserved1{0};
    uint16_t reserved2{0};
    uint32_t offsetData{54};
};

struct BMPInfoHeader {
    uint32_t size{40};
    int32_t width{0};
    int32_t height{0};
    uint16_t planes{1};
    uint16_t bitCount{24};
    uint32_t compression{0};
    uint32_t sizeImage{0};
    int32_t xPixelsPerMeter{0};
    int32_t yPixelsPerMeter{0};
    uint32_t colorsUsed{0};
    uint32_t colorsImportant{0};
};
#pragma pack(pop)

BMPImage::BMPImage(int width, int height) : width(width), height(height) {
    pixels.resize(width * height, {0, 0, 0});
}

BMPImage::BMPImage(const std::string& filename) {
    loadBMP(filename);
}

Pixel BMPImage::getPixel(int x, int y) const {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Coordenadas fuera de los límites");
    }
    return pixels[y * width + x];
}

void BMPImage::setPixel(int x, int y, const Pixel& pixel) {
    if (x < 0 || x >= width || y < 0 || y >= height) {
        throw std::out_of_range("Coordenadas fuera de los límites");
    }
    pixels[y * width + x] = pixel;
}

void BMPImage::invertColors() {
    for (auto& pixel : pixels) {
        pixel.r = 255 - pixel.r;
        pixel.g = 255 - pixel.g;
        pixel.b = 255 - pixel.b;
    }
}

void BMPImage::save(const std::string& filename) {
    saveBMP(filename);
}

void BMPImage::loadBMP(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo");
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    file.read(reinterpret_cast<char*>(&fileHeader), sizeof(fileHeader));
    file.read(reinterpret_cast<char*>(&infoHeader), sizeof(infoHeader));

    if (fileHeader.fileType != 0x4D42) {
        throw std::runtime_error("Formato de archivo no soportado");
    }

    width = infoHeader.width;
    height = infoHeader.height;
    pixels.resize(width * height);

    file.seekg(fileHeader.offsetData, std::ios::beg);

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Pixel pixel;
            file.read(reinterpret_cast<char*>(&pixel.b), 1);
            file.read(reinterpret_cast<char*>(&pixel.g), 1);
            file.read(reinterpret_cast<char*>(&pixel.r), 1);
            setPixel(x, height - 1 - y, pixel); // Los píxeles BMP están invertidos verticalmente
        }
    }
}

void BMPImage::saveBMP(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        throw std::runtime_error("No se pudo abrir el archivo para guardar");
    }

    BMPFileHeader fileHeader;
    BMPInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BMPFileHeader) + sizeof(BMPInfoHeader) + pixels.size() * 3;
    infoHeader.width = width;
    infoHeader.height = height;
    infoHeader.sizeImage = pixels.size() * 3;

    file.write(reinterpret_cast<const char*>(&fileHeader), sizeof(fileHeader));
    file.write(reinterpret_cast<const char*>(&infoHeader), sizeof(infoHeader));

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            Pixel pixel = getPixel(x, height - 1 - y);
            file.write(reinterpret_cast<const char*>(&pixel.b), 1);
            file.write(reinterpret_cast<const char*>(&pixel.g), 1);
            file.write(reinterpret_cast<const char*>(&pixel.r), 1);
        }
    }
}
