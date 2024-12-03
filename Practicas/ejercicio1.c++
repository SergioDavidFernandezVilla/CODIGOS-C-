#include <iostream>
#include <cstdio>

using namespace std;

int main() {

    string name;
    int edad;

    cout << "Ingresa el nombre: " << endl;
    cin >> name;

    cout << "Ingresa la edad: " << endl;
    cin >> edad;

    printf("El nombre es %s y la edad es %i\n", name.c_str(), edad);

    cout << "Finalizado programa" << endl;
    return 0;
}