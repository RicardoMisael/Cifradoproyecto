#ifndef DES_H
#define DES_H

#include <string>

class CifradoDES {
public:
    static std::string rellenar(const std::string& texto) {
        std::string relleno = texto;
        while (relleno.size() % 8 != 0) {
            relleno += ' ';
        }
        return relleno;
    }

    static std::string cifrar(const std::string& texto, const std::string& clave) {
        std::string resultado;
        std::string rellenado = rellenar(texto);
        for (size_t i = 0; i < rellenado.size(); ++i) {
            char c = rellenado[i];
            char k = clave[i % clave.size()];
            resultado += c ^ k;
        }
        return resultado;
    }

    static std::string descifrar(const std::string& texto, const std::string& clave) {
        // Como usamos XOR, el mismo proceso descifra
        return cifrar(texto, clave);
    }
};

#endif
