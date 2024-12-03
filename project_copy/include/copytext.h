#ifdef TEXT_EXTRACTOR_H
#define TEXT_EXTRACTOR_H


#include <string>
#include <vector>
#include <cstdio>

using namespace std;

class TextExtractor {

    // Constructor
    TextExtractor() = default;

    // Metodo para copiar el texto de un archivo txt
    string extraFromText(const string & filePath);

    // Metodo para copiar texto de un archivo .pdf (basico, no cifrado)
    string extraFromPdf(const string & filePath);

    private:
    // Metodo auxiliar para verificar si el archivo existe
    bool fileExists(const string & filePath);
};

#endif // DEBUG