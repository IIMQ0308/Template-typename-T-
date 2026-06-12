#ifndef MENU_H
#define MENU_H
#include "../Services/GenericServices.h"
#include "../models/libros.h"
void mostrarMenu();
void elegirOpcion(int opcion, vector<libros>& registro);
#endif