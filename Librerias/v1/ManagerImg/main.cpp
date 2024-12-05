#include "Image.hpp"
#include <iostream>

int main() {
    try {
        BMPImage image(100, 100);

        // Dibuja un cuadrado rojo
        for (int y = 25; y < 75; ++y) {
            for (int x = 25; x < 75; ++x) {
                image.setPixel(x, y, {255, 0, 0});
            }
        }

        image.save("output.bmp");

        BMPImage loadedImage("output.bmp");
        loadedImage.invertColors();
        loadedImage.save("inverted.bmp");

        std::cout << "Imágenes procesadas y guardadas correctamente." << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
