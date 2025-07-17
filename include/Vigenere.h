#ifndef VIGENERE_H
#define VIGENERE_H

#include <string>

class CifradoVigenere {
public:
    static std::string cifrar(const std::string& texto, const std::string& clave) {
        std::string resultado;
        int claveLen = clave.length();
        for (size_t i = 0; i < texto.length(); ++i) {
            char c = texto[i];
            char k = clave[i % claveLen];
            resultado += c + k;
        }
        return resultado;
    }

    static std::string descifrar(const std::string& texto, const std::string& clave) {
        std::string resultado;
        int claveLen = clave.length();
        for (size_t i = 0; i < texto.length(); ++i) {
            char c = texto[i];
            char k = clave[i % claveLen];
            resultado += c - k;
        }
        return resultado;
    }
};

#endif
