#pragma once
#include <iostream>
#include <string>

using namespace std;

struct DispositivoAudio {
    string id; // Obligatorio iniciar con "COD" según tu servicio
    string marca; // Ej: Sony, Skullcandy
    string modelo;
    string formato; // Ej: Diadema, In-ear, Bocina
    bool cancelacionRuido;

    void mostrar() const {
        cout << "ID: " << id << " | Marca: " << marca 
             << " | Modelo: " << modelo << " | Formato: " << formato 
             << " | ANC: " << (cancelacionRuido ? "Si" : "No") << "\n";
    }
};