#include <iostream>

using namespace std;

struct coordenada
{
    string ciudad;
    char a1;
    char a2;
    char a3;
    char a4;
    char a5;
};


int main(){
    cout << "Tanque = T" << endl
         << "Avion = A"  << endl
         << "Barco = B"  << endl
         << "Carro = C"  << endl
         << "Militar = M"<< endl;
    coordenada b1 = {"Quito", 65, 66 };
    coordenada b2 = {"Guayaquil", 65};
    coordenada b3 = {"Cuenca", 65,67};
    coordenada b4 = {"Ambato", 65, 66, 77};
    coordenada b5 = {"Manta", 66, 77, 84};
    coordenada list [] = {b1, b2, b3, b4, b5};

    cout << endl << "[+] Datos de alumno" << endl
         << "- Cuidad: " << b1.ciudad  << endl
         << "- Armamento 1: " << b1.a1 << endl
         << "- Armamento 2: " << b1.a2 << endl
         << "- Armamento 3: " << b1.a3 << endl
         << "- Armamento 4: " << b1.a4 << endl
         << "- Armamento 5: " << b1.a5 << endl
         << endl;

    for ( auto && COO : list)   // For inteligente 
    {
        cout << endl << "[+] Datos de alumno" << endl
         << "- Cuidad: " << COO.ciudad  << endl
         << "- Armamento 1: " << COO.a1 << endl
         << "- Armamento 2: " << COO.a2 << endl
         << "- Armamento 3: " << COO.a3 << endl
         << "- Armamento 4: " << COO.a4 << endl
         << "- Armamento 5: " << COO.a5 << endl
         << endl;
    }
}