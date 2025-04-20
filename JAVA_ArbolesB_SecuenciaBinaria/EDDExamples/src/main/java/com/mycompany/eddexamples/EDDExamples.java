package com.mycompany.eddexamples;

public class EDDExamples {
    static final int ORDEN = 3;

    public static void imprimir(NodoB nodo, int nivel) {
        if (nodo != null) {
            for (int i = 0; i < nivel; i++) System.out.print("   ");
            for (int clave : nodo.claves) System.out.print(clave + " ");
            System.out.println();
            for (NodoB hijo : nodo.hijos) {
                imprimir(hijo, nivel + 1);
            }
        }
    }

    public static void main(String[] args) {
        NodoB raiz = new NodoB(false);
        raiz.claves.add(10);
        
        NodoB hijoIzquierdo = new NodoB(true);
        hijoIzquierdo.claves.add(5);
        hijoIzquierdo.claves.add(6);

        NodoB hijoDerecho = new NodoB(true);
        hijoDerecho.claves.add(12);
        hijoDerecho.claves.add(20);

        raiz.hijos.add(hijoIzquierdo);
        raiz.hijos.add(hijoDerecho);

        System.out.println("Árbol B de orden 3 (estructura básica):");
        imprimir(raiz, 0);
    }
}