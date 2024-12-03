#include <iostream>
#include <cstdio>

using namespace std;

int main(){

    int max_number;

    cout << "Ingrese un numero maximo: " << endl;
    cin >> max_number;

    if (max_number >= 1){
        cout << "Ha ingresado un numero valido!" << endl;
        cout << "Va comenzar el contador" << endl;

        for (int i = 1; i < max_number; i++)
        {
            printf("Numero actual: %i\n", i);
        }
    } else {
        cout << "No se ha ingresado un numero valido para el contador" << endl;
    }

    cout << "Finalizado" << endl;
}