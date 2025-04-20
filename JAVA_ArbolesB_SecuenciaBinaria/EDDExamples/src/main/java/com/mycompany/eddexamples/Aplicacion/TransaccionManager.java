package com.mycompany.eddexamples.Aplicacion;

/**
 *
 * @author david
 */
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;

public class TransaccionManager {
    // Usamos TreeMap para simular un árbol B (mapa ordenado)
    private static final TreeMap<Integer, String> transacciones = new TreeMap<>();
    private static final Scanner scanner = new Scanner(System.in);

    public static void insertarTransaccion(int id, String descripcion) {
        transacciones.put(id, descripcion);
        System.out.println("Transacción insertada correctamente.");
    }

    public static void buscarTransaccion(int id) {
        if (transacciones.containsKey(id)) {
            System.out.println("ID: " + id + " - Descripción: " + transacciones.get(id));
        } else {
            System.out.println("Transacción no encontrada.");
        }
    }

    public static void mostrarTransacciones() {
        if (transacciones.isEmpty()) {
            System.out.println("No hay transacciones registradas.");
            return;
        }

        System.out.println("Listado de transacciones:");
        for (Map.Entry<Integer, String> entry : transacciones.entrySet()) {
            System.out.println("ID: " + entry.getKey() + " - Descripción: " + entry.getValue());
        }
    }

    public static void mostrarMenu() {
        System.out.println("\n--- Menú de Indexación de Transacciones (Árbol B Simulado) ---");
        System.out.println("1. Insertar nueva transacción");
        System.out.println("2. Buscar transacción por ID");
        System.out.println("3. Mostrar todas las transacciones");
        System.out.println("4. Salir");
        System.out.print("Seleccione una opción: ");
    }

    public static String leerLinea() {
        return scanner.nextLine();
    }

    public static int leerEntero() {
        while (!scanner.hasNextInt()) {
            System.out.print("Ingrese un número válido: ");
            scanner.next();
        }
        int valor = scanner.nextInt();
        scanner.nextLine(); // limpiar el buffer
        return valor;
    }
}
