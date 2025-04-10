#include <iostream>
#include <string>
#include "arbol.h"
using namespace std;

int main() {
    Nodo* raiz = nullptr;
    string opcion;

    cout << "=== Sistema de Autocompletado EDD ===\n";

    while (true) {
        cout << "\nOpciones:\n";
        cout << "1. Ingresar palabra\n";
        cout << "2. Buscar sugerencias\n";
        cout << "3. Mostrar árbol\n";
        cout << "4. Eliminar palabra\n";
        cout << "5. Salir\n";
        cout << "Selecciona una opción: ";
        getline(cin, opcion);

        if (opcion == "1") {
            string palabra;
            cout << "Ingrese una palabra: ";
            getline(cin, palabra);
            raiz = insertar(raiz, palabra);
            cout << "Palabra guardada.\n";

        } else if (opcion == "2") {
            string prefijo;
            cout << "Ingrese el prefijo a buscar: ";
            getline(cin, prefijo);
            mostrarSugerencias(raiz, prefijo);

        } else if (opcion == "3") {
            cout << "\nÁrbol binario de palabras:\n";
            imprimirArbol(raiz);
            cout << "\n";

        } else if (opcion == "4") {
            string palabra;
            cout << "Ingrese la palabra a eliminar: ";
            getline(cin, palabra);
            raiz = eliminar(raiz, palabra);
            cout << "Proceso de eliminación completado.\n";

        } else if (opcion == "4") {
            cout << "Saliendo del programa.\n";
            break;

        }else {
            cout << "Opción no válida. Intente de nuevo.\n";
        }
    }

    return 0;
}
