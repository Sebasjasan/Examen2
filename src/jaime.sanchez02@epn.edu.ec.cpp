#include <iostream>
#include <fstream>
#include <windows.h>
#include <cstdlib>
#include "../lib/colores.h"

using namespace std;

string const jsNombre = "Jaime Sebastian Snachez Gordon";
int const jsCedula = 1752364123;

struct jsCoordenada
{
    int jsCap;
    string jsGeo;
    string jsTipoArsenal;
    jsCoordenada *Izq;
    jsCoordenada *Der;
};

void jsLeerArchivo( string pathFile) 
{
    string s;
    fstream f;
    ifstream jsArch(pathFile.c_str());
    string jsLinea;
    int contador;
    cout<<"\t [+]Leyendo Coordenadas"<<endl;
    cout<<"\t Cap,    Geo,    Tipo Arsenal"<<endl;
    if (!f.is_open()) 
    {
        while (getline(jsArch, jsLinea)) 
        {
            if(contador==0){
                contador++;
                continue;
            }
            int ind =0;
            string c= "-"; 
            for(int i=0; i<= 100; i++)
        {   
            if(i % 4 ==0)
            ind =0;
                cout    << "\r" << c[ind++]   
                << " " << i << "%"<<"   ";
            Sleep(2);
        }
            
            cout << jsLinea << endl;
        }
        f.close();
    }
    else 
    {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

void jsDatos()
{
    cout << COLOR_LBLUE;
    cout << endl
         << "[+] Informacion Arbol Binario de capacidad belica Ucrania" << endl
         << "/Developer-Nombre:"<< jsNombre << endl
         << "Developer-Cedula:" << jsCedula << endl
         << "Capacidad Belica: 34" << endl
         << "Coordenada-Total: 7" << endl
         << "Coordenada/SecCarga: 1 2 3 4 5 6 7  " << endl;
}

struct nodo
{
    string jsCoordenada;
    nodo *izq, *der;
};

void jsInsertar(string jsCoordenada, nodo *&jsArbol)
{
    if (jsArbol == NULL)
    {
        jsArbol = new nodo;
        jsArbol->jsCoordenada = jsCoordenada;
        jsArbol->izq = NULL;
        jsArbol->der = NULL;
    }
    else if (jsCoordenada < jsArbol->jsCoordenada)
    {
        jsInsertar(jsCoordenada, jsArbol->izq);
    }
    else
    {
        jsInsertar(jsCoordenada, jsArbol->der);
    }
}

void jsVerArbol(nodo *jsArbol, int n)
{
    if (jsArbol == NULL)
        return;
    jsVerArbol(jsArbol->der, n + 3);

    for (int i = 0; i < n; i++)
        cout << "   ";

    cout << jsArbol->jsCoordenada << endl;

    jsVerArbol(jsArbol->izq, n + 3);
}

int main()
{
    cout << COLOR_GREEN;
    jsLeerArchivo(".txt/jsCoordenadas.txt");
    system("pause");
    system("cls"); 
    jsDatos();
    system("pause");
    system("cls");
    cout << "\n";

    nodo *jsArbol = NULL;

    cout << COLOR_ROSE;
    cout << "BOMBA TIPO: abcd" << endl;
    jsInsertar("GPS3 {bcd}", jsArbol);
    jsInsertar("GPS2 {ac}", jsArbol);
    jsInsertar("GPS1 {bc}", jsArbol);
    jsInsertar("GPS4 {acd}", jsArbol);
    jsInsertar("GPS6 {act}", jsArbol);
    jsInsertar("GPS5 {bct}", jsArbol);
    jsInsertar("GPS7 {aaabbct}", jsArbol);

    jsVerArbol(jsArbol, 0);
    return 0;
}
