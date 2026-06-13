#include <iostream>
#include "../Services/GenericServices.h"
#include "../models/libros.h"
#include "../utils/menu.h"
#include <string>
#include <vector>
using namespace std;
int main (){
    vector<libro> registro; // Registro global para almacenar los libros
    mostrarMenu(registro);
    return 0;
}
