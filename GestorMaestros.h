#ifndef GESTOR_MAESTROS_H
#define GESTOR_MAESTROS_H

#include <SFML/Graphics.hpp>
#include "ComboBox.h"
#include "Registro.h"

class GestorMaestros {
private:
	Registro user;
public:
	GestorMaestros(const Registro& usuario);
    void run();
    Registro getUser();
};

#endif
