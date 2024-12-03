#ifdef BMP_HANDLER_H
#define BMP_HANDLER_H

#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class BMPHandler {

    public:
    struct BMPImage
    {
        /* data */
        int width, height, bitDepth; // Bits por pixel
        vector<unsigned char> pixelData; // Datos de los pixeles
    };

    static BMPImage load(const string & filePath);
    static bool save(const string & filePath, const BMPImage & image);
    
};

#endif