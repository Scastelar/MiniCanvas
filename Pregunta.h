#ifndef PREGUNTA_H
#define PREGUNTA_H

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

class Pregunta {
private:   
    virtual std::string getTexto() const = 0;
public:
    virtual bool esCorrecta(const std::string& respuesta) const = 0;
    virtual ~Pregunta() {}
};

#endif
