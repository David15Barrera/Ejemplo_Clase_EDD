#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(int val) {
        valor = val;
        izquierdo = derecho = nullptr;
    }
};

// Aqui insertarmos un valor en el árbol binario
Nodo* insertar(Nodo* raiz, int valor) {
    if (raiz == nullptr)
        return new Nodo(valor);

    if (valor < raiz->valor)
        raiz->izquierdo = insertar(raiz->izquierdo, valor);
    else
        raiz->derecho = insertar(raiz->derecho, valor);

    return raiz;
}

// Realizamos el recorrido Inorden (Izquierda, Raíz, Derecha)
void inorden(Nodo* raiz) {
    if (raiz != nullptr) {
        inorden(raiz->izquierdo);
        cout << raiz->valor << " ";
        inorden(raiz->derecho);
    }
}

// Ralizamos el recorrido Preorden (Raíz, Izquierda, Derecha)
void preorden(Nodo* raiz) {
    if (raiz != nullptr) {
        cout << raiz->valor << " ";
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
}

// Realizamos el recorrido Postorden (Izquierda, Derecha, Raíz)
void postorden(Nodo* raiz) {
    if (raiz != nullptr) {
        postorden(raiz->izquierdo);
        postorden(raiz->derecho);
        cout << raiz->valor << " ";
    }
}

int main() {
    Nodo* raiz = nullptr;
    raiz = insertar(raiz, 8);
    insertar(raiz, 3);
    insertar(raiz, 10);
    insertar(raiz, 1);
    insertar(raiz, 6);

    cout << "Recorrido Inorden: ";
    inorden(raiz);
    cout << endl;

    cout << "Recorrido Preorden: ";
    preorden(raiz);
    cout << endl;

    cout << "Recorrido Postorden: ";
    postorden(raiz);
    cout << endl;

    return 0;
}
