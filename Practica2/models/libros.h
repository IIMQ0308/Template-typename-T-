#ifndef LIBROS_H
#define LIBROS_H
#include "Fecha.h"
#include <string>
using namespace std;
struct libro {   //Estructura del libro
    string id;
    string titulo;
    string autor;
    string editorial;
    float precio;
    int paginas;
    Fecha fechaPublicacion;

    //Muestra de la informacion del libro
    void mostrar() const {
        cout << "ID: " << id << endl;
        cout << "Titulo: " << titulo << endl;
        cout << "Autor: " << autor << endl;
        cout << "Editorial: " << editorial << endl;
        cout << "Precio: " << precio << endl;
        cout << "Paginas: " << paginas << endl;
        cout << "Fecha de Publicacion: " << fechaPublicacion.dia << "/" 
             << fechaPublicacion.mes << "/" 
             << fechaPublicacion.anio << endl;
    }
};
//Utilizacion de inline para ignorar los demas includes y evitar problemas de compilacion
//Funcion para agregar las caracteristicas del libro
inline void agregarCaracteristicas(libro& nuevoLibro) {
    cin.ignore(); // Limpia el salto de línea anterior una sola vez
    cout << "Ingrese el titulo del libro: "<< endl;
    getline(cin, nuevoLibro.titulo);
    cout << "Ingrese el autor del libro: "<< endl;
    getline(cin, nuevoLibro.autor);
    cout << "Ingrese la editorial del libro: "<< endl;
    getline(cin, nuevoLibro.editorial);
    cout << "Ingrese el precio del libro: "<< endl;
    cin >> nuevoLibro.precio;
    cout << "Ingrese el numero de paginas del libro: "<< endl;
    cin >> nuevoLibro.paginas;
    cout << "Ingrese la fecha de publicacion del libro: "<<endl;
    cout << "Dia: "; cin >> nuevoLibro.fechaPublicacion.dia;
    cout << "Mes: "; cin >> nuevoLibro.fechaPublicacion.mes;
    cout << "Anio: "; cin >> nuevoLibro.fechaPublicacion.anio;
}
#endif