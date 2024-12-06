#include <cstdio>
#include <iostream>

using namespace std;

class Calcudora{

    public:

    int Suma(int numero1, int numero2){
        return numero1 + numero2;
    }

    int Multiplicador(int numero1, int numero2){
        return numero1 * numero2;
    }

    double Division(int numero1, int numero2){
        return numero1 / numero2;
    }

    int Restar(int numero1, int numero2){
        return numero1 - numero2;
    }
};

int main(){

    int numero1, numero2, opcion;
    Calcudora cal;

    cout << "Calculdora Basica...\n";
    cout << "Opcion 1: Sumar\n";
    cout << "Opcion 2: Mutliplicacion\n";
    cout << "Opcion 3: Division\n";
    cout << "Opcion 4: Restar\n";

    cout << "Ingrese la opcion que prefiere operar: \n";
    cin >> opcion;

    if (opcion >= 1 && opcion <= 4){
        cout << "Ingrese el primer numero: \n";
        cin >> numero1;

        cout << "Ingrese el segundo numero: \n";
        cin >> numero2;
    }

    switch (opcion)
    {
        case 1 :
            cout << "El resultado es suma: " << cal.Suma(numero1, numero2);
        break;

        case 2 :
            cout << "El resultado es Multiplicacion: " << cal.Multiplicador(numero1, numero2);
        break;

        case 3 :
            cout << "El resultado es Division: " << cal.Division(numero1, numero2);
        break;

        case 4 :
            cout << "El resultado es Restar: " << cal.Restar(numero1, numero2);
        break; 
    default:
        cout << "Opcion invalida\n";
        break;
    }

    cout << endl;

    cout << "Finalizado programa \n";
}