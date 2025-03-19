#include "procedimiento.h"

Tarea::Tarea(int _id, string _descripcion) : id(_id), descripcion(_descripcion) {}

// Funcion para mostrar las tareas pendientes dentro de la cola
void mostrarTareasPendientes(queue<Tarea> tareasPendientes) {
    if (tareasPendientes.empty()) {
        cout << "No hay tareas pendientes.\n";
        cout << "\n";
        return;
    }
    cout << "Tareas Pendientes:\n";
    while (!tareasPendientes.empty()) {
        cout << "- [" << tareasPendientes.front().id << "] " << tareasPendientes.front().descripcion << endl;
        cout << "\n";
        tareasPendientes.pop();
    }
}

// FFuncion para mostrar las tareas completadas dento de una pila
void mostrarTareasCompletadas(stack<Tarea> tareasCompletadas) {
    if (tareasCompletadas.empty()) {
        cout << "No hay tareas completadas.\n";
        cout << "\n";
        return;
    }
    cout << "Tareas Completadas:\n";
    while (!tareasCompletadas.empty()) {
        cout << "- [" << tareasCompletadas.top().id << "] " << tareasCompletadas.top().descripcion << endl;
        cout << "\n";
        tareasCompletadas.pop();
    }
}

//Funcion para agregar la tarea a la cola de tareas pendientes
void agregarTarea(queue<Tarea>& tareasPendientes, int& id) {
    string descripcion;
    cout << "Ingrese la descripcion de la tarea: ";
    getline(cin, descripcion);
    tareasPendientes.push(Tarea(id++, descripcion));
    cout << "Tarea agregada.\n";
    cout << "\n";
}

//Funcion que para completar un tarea
void completarTarea(queue<Tarea>& tareasPendientes, stack<Tarea>& tareasCompletadas) {
    if (!tareasPendientes.empty()) {
        Tarea tarea = tareasPendientes.front();
        tareasPendientes.pop();
        tareasCompletadas.push(tarea);
        cout << "Tarea completada: " << tarea.descripcion << endl;
        cout << "\n";
    } else {
        cout << "No hay tareas pendientes.\n";
        cout << "\n";
    }
}

//Funcion para mandar de nuevo a la cola una tarea
void deshacerTarea(stack<Tarea>& tareasCompletadas, queue<Tarea>& tareasPendientes) {
    if (!tareasCompletadas.empty()) {
        Tarea tarea = tareasCompletadas.top();
        tareasCompletadas.pop();
        tareasPendientes.push(tarea);
        cout << "Se deshizo la ultima tarea completada: " << tarea.descripcion << endl;
        cout << "\n";
    } else {
        cout << "No hay tareas para deshacer.\n";
        cout << "\n";
    }
}
