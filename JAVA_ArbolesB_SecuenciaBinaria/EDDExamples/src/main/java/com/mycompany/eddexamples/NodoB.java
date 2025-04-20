package com.mycompany.eddexamples;

import java.util.ArrayList;
import java.util.List;

public class NodoB {
    public List<Integer> claves;
    public List<NodoB> hijos;
    public boolean hoja;

    public NodoB(boolean hoja) {
        this.hoja = hoja;
        this.claves = new ArrayList<>();
        this.hijos = new ArrayList<>();
    }
}
