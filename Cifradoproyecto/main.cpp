#include <iostream>
#include <string>

#include "XOR.h"
#include "Vigenere.h"
#include "Utilidades.h"
#include "GeneradorContrasena.h"
#include "DES.h"
#include "Cesar.h"


using namespace std;
using namespace Utilidades;

void menuPrincipal() {
    int opcion;
    do {
        cout << "\n========= MENU PRINCIPAL =========\n";
        cout << "1. Cifrado Irrompible (XOR + clave aleatoria no guardada)\n";
        cout << "2. Cifrado XOR (clave definida)\n";
        cout << "3. Cifrado Cesar\n";
        cout << "4. Cifrado Vigenere\n";
        cout << "5. Cifrado DES Simulado\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;
        cin.ignore();

        string rutaEntrada, rutaSalida, texto, resultado, clave;
        int desplazamiento;

        switch (opcion) {
        case 1:
            rutaEntrada = pedirRuta("Ruta del archivo a cifrar: ");
            texto = leerArchivo(rutaEntrada);
            clave = GeneradorContrasena::generar(16);
            resultado = CifradoXOR::cifrar(texto, clave);
            rutaSalida = pedirRuta("Ruta para guardar el archivo cifrado: ");
            guardarArchivo(rutaSalida, resultado);
            cout << "[✔] Cifrado exitoso con clave descartada.\n";
            break;

        case 2:
            rutaEntrada = pedirRuta("Ruta del archivo a cifrar/descifrar: ");
            texto = leerArchivo(rutaEntrada);
            clave = pedirTexto("Ingrese la clave XOR: ");
            resultado = CifradoXOR::cifrar(texto, clave);
            rutaSalida = pedirRuta("Ruta para guardar el resultado: ");
            guardarArchivo(rutaSalida, resultado);
            cout << "[✔] Operacion completada (XOR reversible).\n";
            break;

        case 3:
            rutaEntrada = pedirRuta("Ruta del archivo a cifrar/descifrar: ");
            texto = leerArchivo(rutaEntrada);
            desplazamiento = pedirNumero("Ingrese el desplazamiento para Cesar: ");
            resultado = CifradoCesar::cifrar(texto, desplazamiento);
            rutaSalida = pedirRuta("Ruta para guardar el resultado: ");
            guardarArchivo(rutaSalida, resultado);
            cout << "[✔] Cesar cifrado/descifrado completado.\n";
            break;

        case 4:
            rutaEntrada = pedirRuta("Ruta del archivo a cifrar/descifrar: ");
            texto = leerArchivo(rutaEntrada);
            clave = pedirTexto("Ingrese la clave (solo letras): ");
            resultado = CifradoVigenere::cifrar(texto, clave);
            rutaSalida = pedirRuta("Ruta para guardar el resultado: ");
            guardarArchivo(rutaSalida, resultado);
            cout << "[✔] Vigenere cifrado/descifrado completado.\n";
            break;

        case 5:
            rutaEntrada = pedirRuta("Ruta del archivo a cifrar/descifrar: ");
            texto = leerArchivo(rutaEntrada);
            clave = pedirTexto("Clave (1 a 8 caracteres): ");
            resultado = CifradoDES::cifrar(texto, clave);
            rutaSalida = pedirRuta("Ruta para guardar el resultado: ");
            guardarArchivo(rutaSalida, resultado);
            cout << "[✔] DES simulado completado.\n";
            break;

        case 6:
            cout << "Saliendo del programa...\n";
            break;

        default:
            cout << "Opcion no valida. Intente de nuevo.\n";
        }

    } while (opcion != 6);
}

int main() {
    menuPrincipal();
    return 0;
}
