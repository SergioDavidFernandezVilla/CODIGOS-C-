#include "copytext.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <stdexcept>

using namespace std;

bool TextExtractor::fileExists(const string &filePath)
{
    ifstream file(filePath);
    return file.good();
}


    string TextExtractor::extraFromText(const string &filePath)
{
    if (!fileExists(filePath)) {
        throw runtime_error("El achivo no existe: " + filePath);
    }

    ifstream file(filePath);
    ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

string TextExtractor::extraFromPdf(const string & filePath)
{
return string();
}

    string TextExtractor::extractFromPdf(const string& filePath) {
    if (!fileExists(filePath)) {
        throw runtime_error("El archivo no existe: " + filePath);
    }

    ifstream file(filePath, ios::binary);
    if (!file.is_open()) {
        throw runtime_error("No se pudo abrir el archivo PDF: " + filePath);
    }

    ostringstream buffer;
    string line;
    bool inTextObject = false;

    while (getline(file, line)) {
        // Detecta el inicio de un objeto de texto en un PDF básico
        if (line.find("BT") != string::npos) { // "BT" marca el inicio de un texto
            inTextObject = true;
        } else if (line.find("ET") != string::npos) { // "ET" marca el fin de un texto
            inTextObject = false;
        } else if (inTextObject) {
            // Extrae texto contenido entre paréntesis
            size_t start = line.find("(");
            size_t end = line.find(")");

            if (start != string::npos && end != string::npos && start < end) {
                buffer << line.substr(start + 1, end - start - 1) << " ";
            }
        }
    }

    return buffer.str();
}


