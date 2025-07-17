#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <fstream>
#include <sstream>
#include <string>
#include <iostream>

namespace Utilidades {

    std::string leerArchivo(const std::string& ruta) {
        std::ifstream archivo(ruta, std::ios::in);
        if (!archivo.is_open()) {
            std::cerr << "[!] Error al abrir el archivo: " << ruta << "\n";
            return "";
        }

        std::ostringstream ss;
        ss << archivo.rdbuf();
        archivo.close();
        return ss.str();
    }

    bool guardarArchivo(const std::string& ruta, const std::string& contenido) {
        std::ofstream archivo(ruta, std::ios::out);
        if (!archivo.is_open()) {
            std::cerr << "[!] No se pudo guardar el archivo en: " << ruta << "\n";
            return false;
        }

        archivo << contenido;
        archivo.close();
        return true;
    }

    std::string pedirRuta(const std::string& mensaje) {
        std::string ruta;
        std::cout << mensaje;
        std::getline(std::cin, ruta);
        return ruta;
    }

    std::string pedirTexto(const std::string& mensaje) {
        std::string entrada;
        std::cout << mensaje;
        std::getline(std::cin, entrada);
        return entrada;
    }

    int pedirNumero(const std::string& mensaje) {
        int num;
        std::cout << mensaje;
        std::cin >> num;
        std::cin.ignore(); // limpiar el salto de línea
        return num;
    }
}

#endif
