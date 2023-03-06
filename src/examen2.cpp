#include <iostream>
#include <cstdlib>
#include "../lib/colores.h"

using namespace std;

int const TKErr = -1;
int const TKOK = -2;
string const ALFA = "AB \\t";

int **matrizNew(int f, int c)
{
     int **m = NULL;
     m = new int *[f];
     for (int i = 0; i < f; i++)
          m[i] = new int[c];

     return m;
}
void showMatriz(int **pd, int f, int c)
{
     for (int i = 0; i < f; i++)
     {
          for (int j = 0; j < c; j++)
               cout << pd[i][j] << "\t";
          cout << endl;
     }
}

int getIndexAlfabeto(char c)
{
     int index = ALFA.find(c);
     if (index < ALFA.length())
          return index;
     return TKErr;
}

struct nodo
{
     string coordenada;
     nodo *izq, *der;
};

void insertar(string coordenada, nodo *&arbol)
{
     if (arbol == NULL)
     {
          arbol = new nodo;
          arbol->coordenada = coordenada;
          arbol->izq = NULL;
          arbol->der = NULL;
     }
     else if (coordenada < arbol->coordenada)
     {
          insertar(coordenada, arbol->izq);
     }
     else
     {
          insertar(coordenada, arbol->der);
     }
}

void verArbol(nodo *arbol, int n)
{
     if (arbol == NULL)
          return;
     verArbol(arbol->der, n + 3);

     for (int i = 0; i < n; i++)
          cout << "   ";

     cout << arbol->coordenada << endl;

     verArbol(arbol->izq, n + 3);
}

int main()
{
     nodo *arbol = NULL;

     cout << COLOR_LBLUE;
     insertar("Perm 10000 ABT\n", arbol);
     insertar("Izhersk 2000\n", arbol);
     insertar("San petesburgo 1500\n", arbol);
     insertar("Moscu 50000\n", arbol);
     insertar("Kazan 2000 ATC\n", arbol);
     insertar("Novosibirsk 350\n", arbol);
     insertar("Tomsk 500\n", arbol);
     insertar("Omsk 1700\n", arbol);
     insertar("Ussuriisk 2000\n", arbol);
     insertar("Belgorod 3000\n", arbol);

     verArbol(arbol, 0);

     int **mt = NULL;
     int Q = 3, L = 3;
     mt = matrizNew(Q, L);

     mt[0][0] = 1;
     mt[0][1] = 2;
     mt[0][2] = TKErr;
     mt[1][0] = 1;
     mt[1][1] = 2;
     mt[1][2] = TKErr;
     mt[2][0] = TKErr;
     mt[2][1] = TKErr;
     mt[2][2] = TKOK;

     string w = "AAB ";
     int q = 0, l = 0;
     cout << COLOR_BLACK
          << "BOMBA DE TIPO = " << w << endl;

     for (auto &&c : w)
     {
          l = getIndexAlfabeto(c);
          q = mt[q][l];
          // cout << c << " " << q << "," << l << endl;
          if (q == TKErr || q > Q)
               cout << " --> Error";
          if (q == TKOK)
               cout << COLOR_GREEN
                    << "Bomba util para coordenadas 1.1" << endl
                    << "Bomba util para coordenadas 1.2" << endl
                    << "Bomba util para coordenadas 1.3" << endl
                    << COLOR_RED
                    << "La bomba no afecta a las coordenadas 2.1" << endl
                    << "La bomba no afecta a las coordenadas 2.2" << endl
                    << "La bomba no afecta a las coordenadas 2.3" << endl;
     }
     cout << endl;

     return 0;
}
