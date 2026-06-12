#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Producto {
    string id;              
    string nombre;          
    string categoria;       
    double precio;          
    int cantidadEnStock;    

    void mostrar() const {
        cout << "ID: " << id << " | Nombre: " << nombre 
             << " | Categoria: " << categoria << " | Precio: $" << precio 
             << " | Stock: " << cantidadEnStock << "\n";
    }
};