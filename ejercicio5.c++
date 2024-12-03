#include <iostream>
#include <cstdio>

using namespace std;

class Person {

    private: //Atributos
    string name;
    int age;

    public: //Constructor
    Person(string PersonName, int PersonAge){
        name = PersonName;
        age = PersonAge;
    }

    // Metodos

    void SaludarPerson(){
        printf("Welcome %s y con la edad %i\n", name.c_str(), age);
    }

};

int main(){

    string name;
    int age;

    cout << "Ingresa el nombre de la persona: " << endl;
    cin >> name;

    cout << "Ingresa la edad: " << endl;
    cin >> age;

    //CREAR OBJETO
    Person persona(name, age);
    persona.SaludarPerson();

    cout << "Finalizado programa" << endl;
}