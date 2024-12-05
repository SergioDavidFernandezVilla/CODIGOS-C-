#ifndef IMAGE_HPP
#define IMAGE_HPP

#include <string>
#include <vector>
#include <cstdint>

struct Pixel {
    uint8_t r, g, b; // Colores en formato RGB
};

class BMPImage {
private:
    int width, height; // Dimensiones de la imagen
    std::vector<Pixel> pixels; // Almacena los píxeles

    void loadBMP(const std::string& filename);
    void saveBMP(const std::string& filename);

public:
    BMPImage(int width, int height);
    BMPImage(const std::string& filename);

    Pixel getPixel(int x, int y) const;
    void setPixel(int x, int y, const Pixel& pixel);

    void invertColors();
    void save(const std::string& filename);
};

#endif // IMAGE_HPP
