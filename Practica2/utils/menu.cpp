#include <iostream>
#include "menu.h"
#include "../Services/GenericServices.h"
#include "../models/libros.h"
#include <vector>
using namespace std;
void mostrarMenu(){
    cout << "----Menu Principal----" << endl;
    cout << "1. Agregar Producto" << endl;
    cout << "2. Mostrar Productos" << endl;
    cout << "3. Eliminar Producto" << endl;
    cout << "4. Buscar Producto" <<endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
    int opcion;
    libros nuevoElemento;
    cin >> opcion;
    elegirOpcion(opcion, nuevoElemento);
}
void elegirOpcion(int opcion, libros& nuevoElemento){
    switch (opcion)
    {
    case 1: 
        GenericService<libros>::agregar(registros, nuevoElemento);
        mostrarMenu();
        break;
    case 2:
        GenericService<libros>::mostrar(const vector<libros>& registro);
        mostrarMenu();
        break;
    case 3:
        cout << "Ingrese el ID del producto a eliminar: ";
        string id;
        cin >> id;
        GenericService<libros>::eliminar(vector<libros>& registro, const string& id);
        mostrarMenu();
        break;
    case 4:
        cout << "Ingrese el ID del producto a buscar: ";
        string id;
        cin >> id;
        GenericService<libros>::buscar(const vector<libros>& registro, const string& id);
        mostrarMenu();
        break;
    case 5:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
        mostrarMenu();
        break;
    }
}