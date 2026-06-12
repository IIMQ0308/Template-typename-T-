#ifndef GENERIC_SERVICE_H
#define GENERIC_SERVICE_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>

//Definición de la clase genérica
class GenericService{
    public:
        static void agregar(vector<T>& registro, T nuevoElemento);
        static void mostrar(const vector<T>& registro);
        static void eliminar(vector<T>& registro, const string& id);
        static void buscar(const vector<T>& registro, const string& id);
        static bool validarId(const vector<T>& registro, const string& id);
};

//Implementación de los métodos genéricos
template <typename T>
//Create
void GenericService<T>::agregar(vector<T>& registro, T nuevoElemento) {
    registro.push_back(nuevoElemento);
    cout << "Agregado correctamente\n";
}

template <typename T>
//Get All
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
//Delete
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
//Get ID
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
template <typename T>
bool GenericService<T>::validarId(const vector<T>& registro, const string& id){
   if(id.length() <=3 || id.substr(0,3) != "COD"){
    cout << "El ID debe comenzar con 'COD' y tener mas de 3 caracteres"<<endl;   
    return false;
    }
for (const T& indice : registro){
        if (indice.id == id)
        {
            cout << "El ID ya existe, por favor ingrese uno diferente"<< endl;
            return false;
        }
}}
#endif
