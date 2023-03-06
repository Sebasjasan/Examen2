#include <iostream>
#include <fstream> //para archivos
using namespace std;


void LeerArchivo(string pathFile)  
{
    int parrafo = 1;
    string s;
    fstream f;
    f.open(pathFile, ios_base::in);
    if ( !f.is_open() ) 
        cout << "Error de abrir el archivo." << endl;
    else
        do 
        {
            getline( f, s );
            cout << "\t" << s << endl;
            //if (parrafo++%2==0)
            //getchar();  // Para presentar de uno en uno
        }while( !f.eof() );
    f.close();
}
void CrearArchivo(string pathFile)  
{
    string s;
    fstream f;

    cout << "Escibiendo en un archivo" << endl;
    f.open(pathFile, ios_base::out);
    //ios_base::in --> Solo lee, no agrega texto
    //ios_base::app --> Agrega texto
    //ios_base::out --> Escribe y borra el texto anterior
    if (f.is_open())
    {
        do
        {
            cout<< "(N = salir )";
            cin>>s;
            if (s!="N")
                f << s << endl;
        } while (s!="N");
    }
    f.close();
}

int main()
{
    //CrearArchivo(".txt/COO.txt");
    LeerArchivo(".txt/COO.txt");
    return 0;
}