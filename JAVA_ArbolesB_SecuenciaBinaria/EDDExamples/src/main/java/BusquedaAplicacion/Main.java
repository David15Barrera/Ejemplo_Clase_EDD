package BusquedaAplicacion;

/**
 *
 * @author david
 */
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        Inventario inventario = new Inventario();
        int opcion;

        do {
            System.out.println("\n--- MENÚ DE INVENTARIO (BÚSQUEDA SECUENCIAL) ---");
            System.out.println("1. Agregar producto");
            System.out.println("2. Buscar producto por código");
            System.out.println("3. Mostrar todos los productos");
            System.out.println("4. Salir");
            System.out.print("Seleccione una opción: ");
            opcion = scanner.nextInt();
            scanner.nextLine(); // Limpiar buffer

            switch (opcion) {
                case 1:
                    System.out.print("Ingrese código del producto: ");
                    int codigo = scanner.nextInt();
                    scanner.nextLine(); // Limpiar buffer
                    System.out.print("Ingrese nombre del producto: ");
                    String nombre = scanner.nextLine();
                    inventario.agregarProducto(codigo, nombre);
                    break;

                case 2:
                    System.out.print("Ingrese código a buscar: ");
                    int codigoBuscar = scanner.nextInt();
                    Producto producto = inventario.buscarProducto(codigoBuscar);
                    if (producto != null) {
                        System.out.println("Resultado: " + producto);
                    }
                    break;

                case 3:
                    inventario.mostrarProductos();
                    break;

                case 4:
                    System.out.println("Saliendo del sistema...");
                    break;

                default:
                    System.out.println("Opción no válida. Intente nuevamente.");
            }

        } while (opcion != 4);

        scanner.close();
    }
}
