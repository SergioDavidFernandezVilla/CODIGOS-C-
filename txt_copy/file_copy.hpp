#ifdef FILE_COPY_HPP
#define FILE_COPY_HPP



#include <fstream>
#include <string>
#include <iostream>
#include <cstdio>

namespace FileCopy {

    // Función para copiar texto a un archivo
    bool write_to_file(const std::string& filename, const std::string& text) {
        std::ofstream file(filename, std::ios::app); // Abrimos el archivo en modo append
        if (!file.is_open()) {
            std::cerr << "No se pudo abrir el archivo para escribir: " << filename << std::endl;
            return false;
        }
        file << text; // Escribimos el texto en el archivo
        file.close(); // Cerramos el archivo
        return true;
    }

    // Función para leer el contenido de un archivo
    std::string read_from_file(const std::string& filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "No se pudo abrir el archivo para leer: " << filename << std::endl;
            return "";
        }
        std::string content, line;
        while (std::getline(file, line)) {
            content += line + "\n"; // Concatenamos cada línea
        }
        file.close();
        return content;
    }
}

#endif // DEBUG