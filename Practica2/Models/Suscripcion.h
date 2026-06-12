#pragma once
#include <iostream>
#include <string>

using namespace std;

struct Suscripcion {
    string id;
    string plataforma; // Ej: Spotify, HBO Max
    string tipoPlan;   // Ej: Premium, Estudiante
    double costoMensual;
    bool estadoActivo;

    void mostrar() const {
        cout << "ID: " << id << " | Plataforma: " << plataforma 
             << " | Plan: " << tipoPlan << " | Costo: $" << costoMensual 
             << " | Estado: " << (estadoActivo ? "Activa" : "Pausada") << "\n";
    }
};