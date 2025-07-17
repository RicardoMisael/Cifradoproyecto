#ifndef XOR_H
#define XOR_H

#include <string>

class CifradoXOR {
public:
    static std::string cifrar(const std::string& texto, const std::string& clave) {
        std::string resultado;
        for (size_t i = 0; i < texto.size(); ++i) {
            resultado += texto[i] ^ clave[i % clave.size()];
        }
        return resultado;
    }

    // XOR reversible: el mismo método sirve para descifrar
    static std::string descifrar(const std::string& texto, const std::string& clave) {
        return cifrar(texto, clave);
    }
};

#endif
