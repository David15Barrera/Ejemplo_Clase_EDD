#ifndef PROCEDIMIENTO_H
#define PROCEDIMIENTO_H

#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// Structure que representa los atributos de la tarea
struct Tarea {
    int id;
    string descripcion;
    Tarea(int _id, string _descripcion);
};

// Funciones para gestionar las diferentes areas de tareas del programa
void mostrarTareasPendientes(queue<Tarea> tareasPendientes);
void mostrarTareasCompletadas(stack<Tarea> tareasCompletadas);
void agregarTarea(queue<Tarea>& tareasPendientes, int& id);
void completarTarea(queue<Tarea>& tareasPendientes, stack<Tarea>& tareasCompletadas);
void deshacerTarea(stack<Tarea>& tareasCompletadas, queue<Tarea>& tareasPendientes);

#endif