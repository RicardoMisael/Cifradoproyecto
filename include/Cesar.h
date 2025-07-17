#ifndef CESAR_H
#define CESAR_H

#include <string>

class CifradoCesar {
public:
    static std::string cifrar(const std::string& texto, int clave) {
        std::string resultado;
        for (char c : texto) {
            resultado += c + clave;
        }
        return resultado;
    }

    static std::string descifrar(const std::string& texto, int clave) {
        std::string resultado;
        for (char c : texto) {
            resultado += c - clave;
        }
        return resultado;
    }
};

#endif
