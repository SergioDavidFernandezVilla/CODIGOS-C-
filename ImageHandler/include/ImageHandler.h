#ifndef IMAGE_HANDLER_H
#define IMAGE_HANDLER_H

#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class ImageHandler {
    private: 

    // 1: Ancho de la imagen, 2: Alto de la imagen, 3: Canales de color (RGB, RGBA, ETC.), 4: Datos crudos de la imagen
    int width, height, channels;
    vector<unsigned char> data;

    public:
    ImageHandler(); // Constructor por default
    ~ImageHandler(); // Descructor


     // Metodos principales
    bool loadImage(const string & filePath); // Cargar imagen desde un archivo
    bool saveImage(const string & filePath, const string & format); // Guardar imagen

     // Metodos de acceso
    int getWitdh() const;
    int getHeight() const;
    int getChannels() const;

    const vector<unsigned char> & getData() const;

    // Metodos para modificar la imagen (delegados a ImagenProcessor)
    void resize(int newWidth, int newHegiht);
    void converToGrayScale();
};

#endif

