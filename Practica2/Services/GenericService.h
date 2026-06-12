#pragma once
#include <string>
#include <iostream>
#include <vector>

using namespace std;

template <typename T>
class GenericService {
    public:
        static void agregar(vector<T>& registro, T nuevoElemento);
        static void mostrar(const vector<T>& registro);
        static void eliminar(vector<T>& registro, const string& id);
        static void buscar(const vector<T>& registro, const string& id);
};

// --- IMPLEMENTACIÓN DEL TEMPLATE ---

template <typename T>
void GenericService<T>::agregar(vector<T>& registro, T nuevoElemento) {
    if (nuevoElemento.id.length() < 3 || nuevoElemento.id.substr(0, 3) != "COD") {
        cout << "Error: El ID '" << nuevoElemento.id << "' es invalido. Debe iniciar con 'COD'.\n";
        return;
    }

    for (const T& elemento : registro) {
        if (elemento.id == nuevoElemento.id) {
            cout << "Error: El ID '" << nuevoElemento.id << "' ya existe.\n";
            return;
        }
    }

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
            cout << "-------Elemento encontrado-------\n";
            indice.mostrar();
            return;
        }
    }
    cout << "No encontrado\n";
}