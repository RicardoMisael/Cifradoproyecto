#ifndef GENERADOR_CONTRASENA_H
#define GENERADOR_CONTRASENA_H

#include <string>
#include <random>
#include <ctime>

class GeneradorContrasena {
public:
    static std::string generar(int longitud = 16) {
        const std::string caracteres =
            "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
            "abcdefghijklmnopqrstuvwxyz"
            "0123456789"
            "!@#$%^&*()_+-=[]{}|;:,.<>?";

        std::string contrasena;
        std::mt19937 rng(static_cast<unsigned int>(time(nullptr)));
        std::uniform_int_distribution<> dist(0, caracteres.size() - 1);

        for (int i = 0; i < longitud; ++i) {
            contrasena += caracteres[dist(rng)];
        }

        return contrasena;
    }
};

#endif
