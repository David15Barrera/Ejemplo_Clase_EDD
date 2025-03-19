#include <iostream>
#include <queue>
#include <stack>
#include <string>

using namespace std;

// Estructura para representar una tarea
struct Tarea {
    int id;
    string descripcion;
    
    Tarea(int _id, string _descripcion) : id(_id), descripcion(_descripcion) {}
};

// Función para mostrar las tareas pendientes en la cola
void mostrarTareasPendientes(queue<Tarea> tareasPendientes) {
    if (tareasPendientes.empty()) {
        cout << "No hay tareas pendientes.\n";
        return;
    }
    cout << "Tareas Pendientes:\n";
    while (!tareasPendientes.empty()) {
        cout << "- [" << tareasPendientes.front().id << "] " << tareasPendientes.front().descripcion << endl;
        tareasPendientes.pop();
    }
}

// Función para mostrar las tareas completadas en la pila
void mostrarTareasCompletadas(stack<Tarea> tareasCompletadas) {
    if (tareasCompletadas.empty()) {
        cout << "No hay tareas completadas.\n";
        return;
    }
    cout << "Tareas Completadas:\n";
    while (!tareasCompletadas.empty()) {
        cout << "- [" << tareasCompletadas.top().id << "] " << tareasCompletadas.top().descripcion << endl;
        tareasCompletadas.pop();
    }
}

int main() {
    queue<Tarea> tareasPendientes;
    stack<Tarea> tareasCompletadas;
    int opcion, id = 1;
    string descripcion;

    do {
        cout << "\n--- Sistema de Gestion de Tareas ---\n";
        cout << "1. Agregar tarea\n";
        cout << "2. Completar tarea\n";
        cout << "3. Deshacer última tarea completada\n";
        cout << "4. Mostrar tareas pendientes\n";
        cout << "5. Mostrar tareas completadas\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                cout << "Ingrese la descripción de la tarea: ";
                getline(cin, descripcion);
                tareasPendientes.push(Tarea(id++, descripcion));
                cout << "Tarea agregada.\n";
                break;
            
            case 2:
                if (!tareasPendientes.empty()) {
                    Tarea tarea = tareasPendientes.front();
                    tareasPendientes.pop();
                    tareasCompletadas.push(tarea);
                    cout << "Tarea completada: " << tarea.descripcion << endl;
                } else {
                    cout << "No hay tareas pendientes.\n";
                }
                break;

            case 3:
                if (!tareasCompletadas.empty()) {
                    Tarea tarea = tareasCompletadas.top();
                    tareasCompletadas.pop();
                    tareasPendientes.push(tarea);
                    cout << "Se deshizo la última tarea completada: " << tarea.descripcion << endl;
                } else {
                    cout << "No hay tareas para deshacer.\n";
                }
                break;

            case 4:
                mostrarTareasPendientes(tareasPendientes);
                break;

            case 5:
                mostrarTareasCompletadas(tareasCompletadas);
                break;

            case 6:
                cout << "Saliendo del programa...\n";
                break;

            default:
                cout << "Opción no válida.\n";
        }
    } while (opcion != 6);

    return 0;
}
