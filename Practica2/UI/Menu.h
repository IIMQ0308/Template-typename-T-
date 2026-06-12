#pragma once
#include <iostream>
#include <vector>
#include "../Models/Producto.h"
#include "../Services/GenericService.h"
#include "../Utils/ConsoleUtils.h" // <-- Importamos las utilidades

using namespace std;

class Menu {
private:
    vector<Producto> inventarioProductos;

    void agregarProductoInteractivo() {
        ConsoleUtils::limpiarPantalla();
        cout << "--- NUEVO PRODUCTO ---\n";
        
        Producto p;
        string idTemporal;

        cout << "Ingrese el ID (Ej. cod01): ";
        getline(cin, idTemporal);
        
        // Usamos el util para asegurar que el ID siempre esté en mayúsculas
        p.id = ConsoleUtils::aMayusculas(idTemporal); 
        
        cout << "Ingrese el nombre: ";
        getline(cin, p.nombre);
        
        cout << "Ingrese la categoria: ";
        getline(cin, p.categoria);
        
        // Usamos los utils seguros para evitar crasheos en los números
        p.precio = ConsoleUtils::leerDoubleSeguro("Ingrese el precio: $");
        p.cantidadEnStock = ConsoleUtils::leerEnteroSeguro("Ingrese la cantidad en stock: ");

        GenericService<Producto>::agregar(inventarioProductos, p);
        ConsoleUtils::pausar();
    }

public:
    void iniciar() {
        int opcion;
        do {
            ConsoleUtils::limpiarPantalla();
            cout << "\n--- SISTEMA DE GESTION ---\n";
            cout << "1. Agregar Producto (Interactivo)\n";
            cout << "2. Mostrar Productos\n";
            cout << "3. Salir\n";
            
            opcion = ConsoleUtils::leerEnteroSeguro("Opcion: ");

            if (opcion == 1) {
                agregarProductoInteractivo();
            } else if (opcion == 2) {
                ConsoleUtils::limpiarPantalla();
                cout << "\n--- LISTA DE PRODUCTOS ---\n";
                GenericService<Producto>::mostrar(inventarioProductos);
                ConsoleUtils::pausar();
            }

        } while (opcion != 3);
    }
};