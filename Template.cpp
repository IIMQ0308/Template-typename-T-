#include <string>
#include <iostream>
#include <vector>

using namespace std;

// ==========================================
// 1. CLASE GENÉRICA (Código modificado)
// ==========================================
template <typename T>
class GenericService {
    public:
        static void agregar(vector<T>& registro, T nuevoElemento);
        static void mostrar(const vector<T>& registro);
        static void eliminar(vector<T>& registro, const string& id);
        static void buscar(const vector<T>& registro, const string& id);
};

template <typename T>
void GenericService<T>::agregar(vector<T>& registro, T nuevoElemento) {
    // REGLA 1: El ID debe iniciar con "COD"
    // Usamos substr(0, 3) para obtener las primeras 3 letras del ID
    if (nuevoElemento.id.length() < 3 || nuevoElemento.id.substr(0, 3) != "COD") {
        cout << "Error: El ID '" << nuevoElemento.id << "' es invalido. Debe iniciar con 'COD'.\n";
        return;
    }

    // REGLA 2: No permitir IDs duplicados
    for (const T& elemento : registro) {
        if (elemento.id == nuevoElemento.id) {
            cout << "Error: El ID '" << nuevoElemento.id << "' ya existe. No se permiten duplicados.\n";
            return;
        }
    }

    // Si pasa ambas validaciones, se agrega
    registro.push_back(nuevoElemento);
    cout << "Agregado correctamente\n";
}

template <typename T>
void GenericService<T>::mostrar(const vector<T>& registro) {
    if (registro.empty()) {
        cout << "No hay elementos registrados\n";
        return;
    }
    for (const T& indice : registro) {
        indice.mostrar(); 
    }
}

template <typename T>
void GenericService<T>::eliminar(vector<T>& registro, const string& id) {
    for (int i = 0; i < registro.size(); i++) {
        if (registro[i].id == id) {  
            registro.erase(registro.begin() + i);
            cout << "Eliminado correctamente\n";
            return;
        }
    }
    cout << "No encontrado\n";
}

template <typename T>
void GenericService<T>::buscar(const vector<T>& registro, const string& id) {
    for (const T& indice : registro) {
        if (indice.id == id) {
            cout << "-------Producto encontrado-------\n";
            indice.mostrar();
            return;
        }
    }
    cout << "No encontrado\n";
}

// ==========================================
// 2. ESTRUCTURA REQUERIDA
// ==========================================
struct Producto {
    string id;              // Obligatorio
    // 4 atributos adicionales mínimos:
    string nombre;          // Atributo 1
    string categoria;       // Atributo 2
    double precio;          // Atributo 3
    int cantidadEnStock;    // Atributo 4

    // Método mostrar que utiliza el template genérico (debe ser const)
    void mostrar() const {
        cout << "ID: " << id << " | Nombre: " << nombre 
             << " | Categoria: " << categoria << " | Precio: $" << precio 
             << " | Stock: " << cantidadEnStock << "\n";
    }
};

// ==========================================
// 3. FUNCIÓN MAIN (Para ingresar datos)
// ==========================================
int main() {
    vector<Producto> inventario;
    int opcion;

    do {
        cout << "\n--- MENU INVENTARIO ---\n";
        cout << "1. Agregar Producto\n";
        cout << "2. Mostrar Productos\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            Producto p;
            cout << "\nIngrese el ID (Ej. COD01): ";
            cin >> p.id;
            
            // Limpiar el buffer antes de leer strings con espacios
            cin.ignore();
            cout << "Ingrese el nombre: ";
            getline(cin, p.nombre);
            cout << "Ingrese la categoria: ";
            getline(cin, p.categoria);
            cout << "Ingrese el precio: ";
            cin >> p.precio;
            cout << "Ingrese la cantidad en stock: ";
            cin >> p.cantidadEnStock;

            // Llamamos al servicio para intentar agregar el producto
            GenericService<Producto>::agregar(inventario, p);

        } else if (opcion == 2) {
            cout << "\n--- LISTA DE PRODUCTOS ---\n";
            GenericService<Producto>::mostrar(inventario);
        }

    } while (opcion != 3);

    return 0;
}