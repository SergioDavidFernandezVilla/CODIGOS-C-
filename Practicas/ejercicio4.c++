#include <cstdio>
#include <iostream>

using namespace std;

class Operacion {
    private:
    int num1, num2; //Atributo privado

    public: //Constructor para inicializar los numeros
        Operacion(int n1, int n2){
            num1 = n1;
            num2 = n2;
        }

        // Metodo para realizar suma
        int Sumar(){
            return num1 + num2;
        }

        // Metodo para mostrar el resultado
        void MostrarResultado(){
            cout << "El resultado de la suma es: " << Sumar() << endl;
        }

};

int main(){

   
   int numero1, numero2;

    cout << "Ingrese el primer numero:\n";
    cin >> numero1;

    cout << "Ingrese el segundo numero:\n";
    cin >> numero2;

    // Crear un objeto de la clase "Operacion"
    Operacion operacion(numero1, numero2);

    // Llamamos al método MostrarResultado del objeto
    operacion.MostrarResultado();

    cout << "Finalizado programa" << endl;
}