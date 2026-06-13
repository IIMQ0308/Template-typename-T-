#include <iostream>
#include "menu.h"
#include "../Services/GenericServices.h"
#include "../models/libros.h"
#include <vector>
using namespace std;
// Funcion para mostrar el menu
void mostrarMenu(vector<libro>& registro){
    cout << "----Menu Principal----" << endl;
    cout << "1. Agregar Producto" << endl;
    cout << "2. Mostrar Productos" << endl;
    cout << "3. Eliminar Producto" << endl;
    cout << "4. Buscar Producto" <<endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione una opcion: ";
    int opcion;
    cin >> opcion;
    elegirOpcion(opcion, registro);
}
//Funcion para elegir la opcion
void elegirOpcion(int opcion, vector<libro>&registro){
    switch (opcion)
    {
    case 1:{
        libro nuevoElemento; // Crear un nuevo libro de tipo estructura Libro
        while(true){ //Repetir el ciclo mientras la validacion sea verdadera
        cout << "Ingrese el ID del libro: " << endl;
        cin >> nuevoElemento.id; // Elegir el ID del nuevo libro
            if (GenericService<libro>::validarId(registro, nuevoElemento.id)){ //Llama a la funcion para validar
             break; //romper el ciclo si es verdadero
            }
        }
        agregarCaracteristicas(nuevoElemento); // Llamar funcion de lista de datos
        GenericService<libro>::agregar(registro, nuevoElemento); // Llamar funcion generica
        mostrarMenu(registro); // Regresar a menu
        break; }
    case 2:
        GenericService<libro>::mostrar(registro); // Funcion generica
        mostrarMenu(registro); // Regresar a menu
        break;
    case 3:{
        cout << "Ingrese el ID del producto a eliminar: ";
        string id;
        cin >> id;
        GenericService<libro>::eliminar(registro, id); // Funcion generica
        mostrarMenu(registro); // Regresar a menu
        break;}
    case 4:{
        cout << "Ingrese el ID del producto a buscar: ";
        string id;
        cin >> id;
        GenericService<libro>::buscar(registro, id); // funcion generica
        mostrarMenu(registro); // regresar a menu
        break;}
    case 5:
        cout << "Saliendo..." << endl;
        break;
    default:
        cout << "Opcion no valida" << endl;
        mostrarMenu(registro);
        break;
    }
}