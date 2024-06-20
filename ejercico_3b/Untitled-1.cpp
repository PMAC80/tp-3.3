#include <iostream>   // Incluye la biblioteca de entrada/salida estándar
#include <fstream>    // Incluye la biblioteca para manejo de archivos
#include <string>     // Incluye la biblioteca para manejo de strings

using namespace std;

int main() {
    string frase;  // Variable para almacenar cada frase ingresada por el usuario

    // Abre un archivo para escritura, si no existe lo crea; si existe, lo sobrescribe
    ofstream archivoSalida("frasesDeBjarme.txt");

    // Verifica si el archivo se abrió correctamente
    if (archivoSalida.is_open()) {
        // Instrucciones para el usuario
        cout << "Ingresa las frases que deseas guardar. Escribe 'fin' para terminar." << endl;

        // Lee frases hasta que se ingrese "fin"
        do {
            // Lee una frase desde la entrada estándar
            getline(cin, frase);

            // Verifica si la frase es diferente de "fin"
            if (frase != "fin") {
                // Escribe la frase en el archivo, seguida de un salto de línea
                archivoSalida << frase << endl;
            }
        } while (frase != "fin");

        // Cierra el archivo después de terminar la escritura
        archivoSalida.close();

        // Mensaje de confirmación en consola
        cout << "Se han guardado las frases en el archivo 'frasesDeBjarme.txt'" << endl;
    } else {
        // Muestra un mensaje de error si no se pudo abrir el archivo
        cerr << "Error al abrir el archivo para escritura" << endl;
        return 1;  // Sale del programa con un código de error
    }

    // Abrir el archivo para lectura
    ifstream archivoEntrada("frasesDeBjarme.txt");

    // Verifica si el archivo se abrió correctamente
    if (archivoEntrada.is_open()) {
        cout << "\nLas frases guardadas son:\n" << endl;

        // Lee el archivo línea por línea
        while (getline(archivoEntrada, frase)) {
            // Muestra cada línea leída en la consola
            cout << frase << endl;
            cout << endl;  // Imprime una línea vacía para interlineado
        }

        // Cierra el archivo después de terminar la lectura
        archivoEntrada.close();
    } else {
        // Muestra un mensaje de error si el archivo no se pudo abrir
        cerr << "Error al abrir el archivo para lectura" << endl;
        return 1;  // Sale del programa con un código de error
    }

    return 0;  // Indica que el programa finalizó correctamente
}
