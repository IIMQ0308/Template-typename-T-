#ifndef LIBROS_H
#define LIBROS_H
#include "Fecha.h"
#include <string>
using namespace std;
struct libros{
    string id;
    string titulo;
    string autor;
    string editorial;
    float precio;
    int paginas;
    Fecha fechaPublicacion;
};
void agregarCaracteristicas(libros& nuevoLibro){
    cout << "Ingrese el ID del libro: "<< endl;
    cin.ignore();
    getline(cin, nuevoLibro.id);
    cout << "Ingrese el titulo del libro: "<< endl;
    cin.ignore();
    getline(cin, nuevoLibro.titulo);
    cout << "Ingrese el autor del libro: "<< endl;
    cin.ignore();
    getline(cin, nuevoLibro.autor);
    cout << "Ingrese la editorial del libro: "<< endl;
    cin.ignore();
    getline(cin, nuevoLibro.editorial);
    cout << "Ingrese el precio del libro: "<< endl;
    cin >> nuevoLibro.precio;
    cout << "Ingrese el numero de paginas del libro: "<< endl;
    cin >> nuevoLibro.paginas;
    cout << "Ingrese la fecha de publicacion del libro: "<<endl;
    cout << "Dia: ";
    cin >> nuevoLibro.fechaPublicacion.dia;
    cout << "Mes: ";
    cin >> nuevoLibro.fechaPublicacion.mes;
    cout << "Anio: ";
    cin >> nuevoLibro.fechaPublicacion.anio;
}
void mostrarlibros(const libros& libros){
    cout << "ID: " << libros.id << endl;
    cout << "Titulo: " << libros.titulo << endl;
    cout << "Autor: " << libros.autor << endl;
    cout << "Editorial: " << libros.editorial << endl;
    cout << "Precio: " << libros.precio << endl;
    cout << "Paginas: " << libros.paginas << endl;
    cout << "Fecha de Publicacion: " << libros.fechaPublicacion.dia << "/" 
         << libros.fechaPublicacion.mes << "/" 
         << libros.fechaPublicacion.anio << endl;
};
#endif