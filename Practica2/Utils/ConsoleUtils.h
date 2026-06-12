#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <algorithm>

using namespace std;

class ConsoleUtils {
public:
    // 1. Limpiar pantalla (Multiplataforma)
    static void limpiarPantalla() {
        #ifdef _WIN32
            system("cls");
        #else
            system("clear");
        #endif
    }

    // 2. Pausar el sistema
    static void pausar() {
        cout << "\nPresione ENTER para continuar...";
        cin.get();
    }

    // 3. Leer un entero de forma segura (evita que el programa colapse)
    static int leerEnteroSeguro(const string& mensaje) {
        int valor;
        while (true) {
            cout << mensaje;
            if (cin >> valor) {
                // Limpiamos el buffer correctamente
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            } else {
                cout << "-> Error: Entrada invalida. Por favor ingrese un numero entero.\n";
                cin.clear(); // Limpia el estado de error de cin
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Descarta la mala entrada
            }
        }
    }

    // 4. Leer un double de forma segura (ideal para precios)
    static double leerDoubleSeguro(const string& mensaje) {
        double valor;
        while (true) {
            cout << mensaje;
            if (cin >> valor) {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                return valor;
            } else {
                cout << "-> Error: Entrada invalida. Por favor ingrese un numero decimal valido.\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }

    // 5. Convertir un string a mayúsculas (útil para forzar el formato del ID "COD")
    static string aMayusculas(string texto) {
        transform(texto.begin(), texto.end(), texto.begin(), ::toupper);
        return texto;
    }
};