#include <iostream>   
#include <fstream>    
#include <string>     

using namespace std;

void clearConsole();
int contarPalabras(string linea);

int main() {

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

        cout << "Se han guardado las frases en el archivo 'frasesDeBjarme.txt'" << endl;
    } 
    else 
    {
        cerr << "Error al abrir el archivo para escritura" << endl;
        return 1;  
    }

    int totalPalabras = 0;
    int totalLineas = 0;

    ifstream archivoEntrada("frasesDeBjarme.txt");

    if (archivoEntrada.is_open()) {
        cout << "\nLas frases guardadas son:\n" << endl;

        // Lee el archivo línea por línea
        while (getline(archivoEntrada, frase)) {
            // Muestra cada línea leída en la consola
            cout << frase << endl;
            cout << endl;  // Imprime una línea vacía para interlineado

            // Cuenta las palabras en la línea actual
            int palabrasEnLinea = contarPalabras(frase);

            // Muestra la cantidad de palabras en la línea actual
            cout << "Palabras en esta línea: " << palabrasEnLinea << endl;
            cout << endl;

            // Acumula el total de palabras y líneas
            totalPalabras += palabrasEnLinea;
            totalLineas++;
        }

        // Cierra el archivo después de terminar la lectura
        archivoEntrada.close();

        // Muestra la cantidad total de palabras y el promedio de palabras por línea
        cout << "Cantidad total de palabras: " << totalPalabras << endl;
        if (totalLineas > 0) {
            double promedioPalabrasPorLinea = static_cast<double>(totalPalabras) / totalLineas;
            cout << "Promedio de palabras por línea: " << promedioPalabrasPorLinea << endl;
        }
    } else {
        // Muestra un mensaje de error si el archivo no se pudo abrir
        cerr << "Error al abrir el archivo para lectura" << endl;
        return 1;  // Sale del programa con un código de error
    }

    return 0;  // Indica que el programa finalizó correctamente
}

// Definición de la función para contar palabras en una línea
int contarPalabras(string linea) {
    int cuenta = 0;
    bool enPalabra = false;

    for (char c : linea) {
        if (isspace(c)) {
            if (enPalabra) {
                cuenta++;
                enPalabra = false;
            }
        } else {
            enPalabra = true;
        }
    }

    if (enPalabra) {
        cuenta++;
    }

    return cuenta;
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