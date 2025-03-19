#include <iostream>
#include "procedimiento.h"

using namespace std;

int main() {
    queue<Tarea> tareasPendientes;
    stack<Tarea> tareasCompletadas;
    int opcion, id = 1;

    do {
        std::cout << "--- Uso de Pilas y Colas ---" << std::endl;
        std::cout << "--- Gestion de Tareas ---" << std::endl;
        std::cout << "1. Agregar tarea" << std::endl;
        std::cout << "2. Completar tarea" << std::endl;
        std::cout << "3. Deshacer ultima tarea completada" << std::endl;
        std::cout << "4. Mostrar tareas pendientes" << std::endl;
        std::cout << "5. Mostrar tareas completadas" << std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Seleccione una opcion: " << std::endl;
        cin >> opcion;
        cin.ignore();

        switch (opcion) {
            case 1:
                agregarTarea(tareasPendientes, id);
                break;
            case 2:
                completarTarea(tareasPendientes, tareasCompletadas);
                break;
            case 3:
                deshacerTarea(tareasCompletadas, tareasPendientes);
                break;
            case 4:
                mostrarTareasPendientes(tareasPendientes);
                break;
            case 5:
                mostrarTareasCompletadas(tareasCompletadas);
                break;
            case 6:
                std::cout << "Gracias por utilizar el programa" << std::endl;
                break;
            default:
                std::cout << "Opcion no valida" << std::endl;
        }
    } while (opcion != 6);

    return 0;
}
