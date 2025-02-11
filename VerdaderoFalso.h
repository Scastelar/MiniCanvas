#ifndef VERDADERO_FALSO_H
#define VERDADERO_FALSO_H

#include "Pregunta.h"

class VerdaderoFalso : public Pregunta {
    std::string texto;
    bool respuestaCorrecta;

public:
    VerdaderoFalso(const std::string& texto, bool respuesta)
        : texto(texto), respuestaCorrecta(respuesta) {}

    std::string getTexto() const override {
        return texto + " (V/F)";
    }

    bool esCorrecta(const std::string& respuesta) const override {
        return (respuesta == "V" && respuestaCorrecta) || (respuesta == "F" && !respuestaCorrecta);
    }
};

#endif
