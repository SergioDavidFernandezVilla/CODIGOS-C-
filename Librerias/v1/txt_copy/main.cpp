#include <iostream>
#include "file_copy.hpp"
#include <cstdio>

using namespace std;

int main(){
    string filename = "example.txt";
    string text_to_copy = "Este es un texto de prueba.\nOtro texto más.\n";

    // Escribir texto en el archivo
    if (FileCopy::write_to_file(filename, text_to_copy)){
        cout << "Texto copiado correctamente a " << filename << endl; 
    }

    // Leer el contenido del archivo
    string content = FileCopy::read_from_file(filename);
    cout << "Contenido del archivo: \n" << content << endl;

    return 0;
}