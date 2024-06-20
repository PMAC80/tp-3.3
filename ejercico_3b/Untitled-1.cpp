#include <iostream>   
#include <fstream>   
#include <string>    

using namespace std;

void clearConsole();

int main() 
{
    clearConsole();

    string frase;     
    ofstream archivoSalida("frasesDeBjarme.txt");

    if (archivoSalida.is_open()) 
    {
        cout << "Ingresa las frases que deseas guardar. Escribe 'fin' para terminar." << endl;
       
        do
        {
            getline(cin, frase);

            if (frase != "fin") 
            {
                archivoSalida << frase << endl;
            }

        } while (frase != "fin");

        archivoSalida.close();

        cout << "Se han guardado las frases en el archivo" << endl;
    } else {
        cerr << "Error al abrir el archivo para escritura" << endl;
        return 1;  
    }

    ifstream archivoEntrada("frasesDeBjarme.txt");

    if (archivoEntrada.is_open()) 
    {
        cout << "\nLas frases guardadas son:\n" << endl;

        while (getline(archivoEntrada, frase)) 
        {
            cout << frase << endl;
            cout << endl;  
        }
        archivoEntrada.close();
    } 
    else 
    {
        cerr << "Error al abrir el archivo para lectura" << endl;
        return 1;  
    }

    return 0;  
}
void clearConsole() {
    #ifdef __unix__
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif defined(_WIN32) || defined(WIN64)
        system("cls");
    #endif
}
