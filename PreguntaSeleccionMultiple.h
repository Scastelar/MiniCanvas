#ifndef PREGUNTA_SELECCION_H
#define PREGUNTA_SELECCION_H

#include "Pregunta.h"

class PreguntaSeleccionMultiple : public Pregunta {
    std::string texto;
    std::vector<std::string> opciones;
    int respuestaCorrecta; // índice de la respuesta correcta

public:
    PreguntaSeleccionMultiple(const std::string& texto, const std::vector<std::string>& opciones, int respuesta)
        : texto(texto), opciones(opciones), respuestaCorrecta(respuesta) {}

    std::string getTexto() const override {
        std::string resultado = texto + "\n";
        for (size_t i = 0; i < opciones.size(); ++i) {
            resultado += std::to_string(i + 1) + ". " + opciones[i] + "\n";
        }
        return resultado;
    }

    bool esCorrecta(const std::string& respuesta) const override {
        return std::stoi(respuesta) - 1 == respuestaCorrecta;
    }
};


#endif
