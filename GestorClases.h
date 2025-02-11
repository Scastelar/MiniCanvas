#ifndef GESTOR_CLASES_H
#define GESTOR_CLASES_H

#include <SFML/Graphics.hpp>
#include "Registro.h"

class GestorClases {
private:
    Registro user;  
public:
    GestorClases(Registro usuario);
    void run();
    Registro getUser();
    void addClass();
    void eliminarClase();
};

#endif

