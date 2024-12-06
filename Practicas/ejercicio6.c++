#include <iostream>
#include <cstdio>

using namespace std;

int main(int argc, const char** argv) {
   
   string texto;

   cout << "Ingrese el texto deseado: " << endl;
   cin >> texto;

   cout << "Valores ASCII del texto ingresado: ";

   for(char c : texto){
        cout << int(c) << " ";
   }

   cout << endl;
   
    return 0;
}