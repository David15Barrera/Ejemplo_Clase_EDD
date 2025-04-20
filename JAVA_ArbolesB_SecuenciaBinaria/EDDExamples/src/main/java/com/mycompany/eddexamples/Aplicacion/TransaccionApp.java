package com.mycompany.eddexamples.Aplicacion;

/**
 *
 * @author david
 */
public class TransaccionApp {
    public static void main(String[] args) {
        // Transacciones precargadas
        TransaccionManager.insertarTransaccion(1001, "Compra en Supermercado");
        TransaccionManager.insertarTransaccion(1002, "Transferencia bancaria");
        TransaccionManager.insertarTransaccion(1003, "Pago de servicios");

        int opcion;
        do {
            TransaccionManager.mostrarMenu();
            opcion = TransaccionManager.leerEntero();

            switch (opcion) {
                case 1 -> {
                    System.out.print("Ingrese ID de la transacción: ");
                    int id = TransaccionManager.leerEntero();
                    System.out.print("Ingrese descripción: ");
                    String descripcion = TransaccionManager.leerLinea();
                    TransaccionManager.insertarTransaccion(id, descripcion);
                }
                case 2 -> {
                    System.out.print("Ingrese ID de transacción a buscar: ");
                    int id = TransaccionManager.leerEntero();
                    TransaccionManager.buscarTransaccion(id);
                }
                case 3 -> TransaccionManager.mostrarTransacciones();
                case 4 -> System.out.println("Saliendo del sistema...");
                default -> System.out.println("Opción inválida. Intente de nuevo.");
            }

        } while (opcion != 4);
    }
}
