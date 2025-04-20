
package busquedaLineal;

/**
 *
 * @author david
 */
public class BusquedaLineal {
    public static void main(String[] args) {
        int[] arreglo = {4, 9, 1, 6, 2, 10};
        int buscar = 9;
        boolean encontrado = false;

        for (int i = 0; i < arreglo.length; i++) {
            if (arreglo[i] == buscar) {
                System.out.println("Encontrado en la posición " + i);
                encontrado = true;
                break;
            }
        }

        if (!encontrado) {
            System.out.println("No se encontró el valor.");
        }
    }
}
