#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int main(){

    vector<string> data = {"hola", "21", "estas"};

    for (size_t i = 0; i < data.size(); i++)
    {
        cout << data[i] << " " << "\n";
    }

    cout << "Finalizado programa \n";
    return 0;
}