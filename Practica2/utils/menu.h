#ifndef MENU_H
#define MENU_H
#include <vector>
#include "../Services/GenericServices.h"
#include "../models/libros.h"
using namespace std;
void mostrarMenu(vector<libro>& registro);
void elegirOpcion(int opcion, vector<libro>& registro);
#endif