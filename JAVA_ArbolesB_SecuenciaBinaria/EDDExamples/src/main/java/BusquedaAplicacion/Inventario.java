package BusquedaAplicacion;
import java.util.ArrayList;
import java.util.List;
/**
 *
 * @author david
 */

public class Inventario {
    private List<Producto> productos;

    public Inventario() {
        productos = new ArrayList<>();
        // Datos iniciales
        productos.add(new Producto(1001, "Leche"));
        productos.add(new Producto(1002, "Pan"));
        productos.add(new Producto(1003, "Huevos"));
        productos.add(new Producto(1004, "Arroz"));
    }

    public void agregarProducto(int codigo, String nombre) {
        productos.add(new Producto(codigo, nombre));
        System.out.println("Producto agregado exitosamente.");
    }

    public Producto buscarProducto(int codigo) {
        System.out.println("\nIniciando búsqueda secuencial...");
        for (int i = 0; i < productos.size(); i++) {
            System.out.println("Comparando con producto en posición " + i + ": " + productos.get(i).getCodigo());
            if (productos.get(i).getCodigo() == codigo) {
                System.out.println("¡Producto encontrado en la posición " + i + "!");
                return productos.get(i);
            }
        }
        System.out.println("Producto no encontrado tras recorrer todos los elementos.");
        return null;
    }

    public void mostrarProductos() {
        if (productos.isEmpty()) {
            System.out.println("No hay productos registrados.");
        } else {
            System.out.println("\nLista de productos:");
            for (Producto p : productos) {
                System.out.println(p);
            }
        }
    }
}
