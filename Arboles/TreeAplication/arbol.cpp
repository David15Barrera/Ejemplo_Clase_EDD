#include "arbol.h"
#include <iostream>
#include <algorithm>

Nodo::Nodo(string p) : palabra(p), frecuencia(1), izq(nullptr), der(nullptr) {}

Nodo* insertar(Nodo* raiz, string palabra) {
    if (raiz == nullptr) return new Nodo(palabra);

    if (palabra == raiz->palabra) {
        raiz->frecuencia++;
    } else if (palabra < raiz->palabra) {
        raiz->izq = insertar(raiz->izq, palabra);
    } else {
        raiz->der = insertar(raiz->der, palabra);
    }
    return raiz;
}

void buscarSugerencias(Nodo* raiz, string prefijo, vector<pair<string, int>>& resultados) {
    if (raiz == nullptr) return;

    buscarSugerencias(raiz->izq, prefijo, resultados);

    if (raiz->palabra.find(prefijo) == 0) {
        resultados.push_back({raiz->palabra, raiz->frecuencia});
    }

    buscarSugerencias(raiz->der, prefijo, resultados);
}

void mostrarSugerencias(Nodo* raiz, string prefijo) {
    vector<pair<string, int>> resultados;
    buscarSugerencias(raiz, prefijo, resultados);

    sort(resultados.begin(), resultados.end(), [](auto& a, auto& b) {
        return b.second < a.second;
    });

    if (resultados.empty()) {
        cout << "No hay sugerencias para el prefijo \"" << prefijo << "\"\n";
    } else {
        cout << "Sugerencias para \"" << prefijo << "\":\n";
        for (auto& p : resultados) {
            cout << "- " << p.first << " (usada " << p.second << " veces)\n";
        }
    }
}

void imprimirArbol(Nodo* raiz, int espacio, int nivel) {
    if (raiz == nullptr)
        return;

    espacio += nivel;
    imprimirArbol(raiz->der, espacio);

    cout << endl;
    for (int i = nivel; i < espacio; i++)
        cout << " ";
    cout << raiz->palabra << "(" << raiz->frecuencia << ")";

    imprimirArbol(raiz->izq, espacio);
}


Nodo* encontrarMinimo(Nodo* nodo) {
    while (nodo && nodo->izq != nullptr)
        nodo = nodo->izq;
    return nodo;
}

Nodo* eliminar(Nodo* raiz, string palabra) {
    if (raiz == nullptr) return nullptr;

    if (palabra < raiz->palabra) {
        raiz->izq = eliminar(raiz->izq, palabra);
    } else if (palabra > raiz->palabra) {
        raiz->der = eliminar(raiz->der, palabra);
    } else {
        // Encontrando el nodo encontrado
        if (raiz->frecuencia > 1) {
            // disminuimos la frecuencia si hay repeticiones
            raiz->frecuencia--;
            return raiz;
        }

        // Caso 1: sin hijos
        if (raiz->izq == nullptr && raiz->der == nullptr) {
            delete raiz;
            return nullptr;
        }

        // Caso 2: con un hijo
        if (raiz->izq == nullptr) {
            Nodo* temp = raiz->der;
            delete raiz;
            return temp;
        }
        if (raiz->der == nullptr) {
            Nodo* temp = raiz->izq;
            delete raiz;
            return temp;
        }

        // Caso 3: cuando tengamos dos hijos
        Nodo* sucesor = encontrarMinimo(raiz->der);
        raiz->palabra = sucesor->palabra;
        raiz->frecuencia = sucesor->frecuencia;
        raiz->der = eliminar(raiz->der, sucesor->palabra);
    }
    return raiz;
}
