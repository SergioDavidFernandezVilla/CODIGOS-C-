#include "project_copy/include/copytext.h"
#include <iostream>

int main() {
    TextExtractor extractor;

    try {
        std::string txtContent = extractor.extractFromTxt("archivo.txt");
        std::cout << "Contenido del archivo .txt:\n" << txtContent << "\n";

        std::string pdfContent = extractor.extractFromPdf("archivo.pdf");
        std::cout << "Contenido del archivo .pdf:\n" << pdfContent << "\n";

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
    }

    return 0;
}
