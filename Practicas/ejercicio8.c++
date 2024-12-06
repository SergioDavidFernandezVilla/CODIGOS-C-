#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int numberList, multiple;

    cout << "Ingrese el numero maximo del arreglo: \n";
    cin >> numberList;

    cout << "Ingrese el numero que se va usar para multiplicar : \n";
    cin >> multiple;

    if (multiple == 0) {
        cout << "Por favor, ingrese un multiple valido. No se permite un valor menor de 1 \n";
    } else {


    int* arr = new int[numberList];

    for (int i = 0; i < numberList; i++)
    {
        /* code */
        arr[i] = i * multiple; // Inicializamos con múltiplos de 2
    }
    

    for (int i = 1; i < numberList; i++)
    {
        cout << arr[i] * 2 << " ";
    }

    delete[] arr;

    cout << "\n";


    }

   

    cout << "Finalizado programa \n";
    return 0;
}