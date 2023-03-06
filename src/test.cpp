#include <iostream>
#include <fstream> //para archivos
#include "../lib/colores.h"

using namespace std;

struct Nodo {
    string palabra;
    Nodo* izquierda;
    Nodo* derecha;
};

void insertarNodo(string palabra, Nodo*& raiz) {
    if (raiz == nullptr) {
        raiz = new Nodo;
        raiz->palabra = palabra;
        raiz->izquierda = nullptr;
        raiz->derecha = nullptr;
    }
    else if (palabra < raiz->palabra) {
        insertarNodo(palabra, raiz->izquierda);
    }
    else {
        insertarNodo(palabra, raiz->derecha);
    }
}

void verArbol(Nodo* raiz, int n)
{
     if(raiz==nullptr)
          return;
     verArbol(raiz->derecha, n+3);

     for(int i=0; i<n; i++)
         cout<<"   ";

     cout<< raiz->palabra <<endl;

     verArbol(raiz->izquierda, n+3);
}

int main() {
    Nodo* raiz = nullptr;
    
    cout << COLOR_LBLUE;
    insertarNodo("Perm 10000 ABT\n", raiz);
    insertarNodo("Izhersk 2000\n", raiz);
    insertarNodo("San petesburgo 1500\n", raiz);
    insertarNodo("Moscu 50000\n", raiz);
    insertarNodo("Kazan 2000 ATC\n", raiz);
    insertarNodo("Novosibirsk 350\n", raiz);
    insertarNodo("Tomsk 500\n", raiz);
    insertarNodo("Omsk 1700\n", raiz);
    insertarNodo("Ussuriisk 2000\n", raiz);
    insertarNodo("Belgorod 3000\n", raiz);

    verArbol(raiz, 0);

    return 0;
}