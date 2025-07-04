package BusquedaAplicacion;

/**
 *
 * @author david
 */
public class Producto {
    private int codigo;
    private String nombre;

    public Producto(int codigo, String nombre) {
        this.codigo = codigo;
        this.nombre = nombre;
    }

    public int getCodigo() {
        return codigo;
    }

    public String getNombre() {
        return nombre;
    }

    @Override
    public String toString() {
        return "Código: " + codigo + " - Nombre: " + nombre;
    }
}
