#ifndef ARBOL_H
#define ARBOL_H

#include <string>
#include <vector>
using namespace std;

struct Nodo {
    string palabra;
    int frecuencia;
    Nodo* izq;
    Nodo* der;

    Nodo(string p);
};

Nodo* insertar(Nodo* raiz, string palabra);
Nodo* eliminar(Nodo* raiz, string palabra);
void buscarSugerencias(Nodo* raiz, string prefijo, vector<pair<string, int>>& resultados);
void mostrarSugerencias(Nodo* raiz, string prefijo);
void imprimirArbol(Nodo* raiz, int espacio = 0, int nivel = 5);

#endif
