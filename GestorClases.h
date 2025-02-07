#ifndef GESTOR_CLASES_H
#define GESTOR_CLASES_H

#include <SFML/Graphics.hpp>
#include "ComboBox.h"
#include "Registro.h"


class GestorClases {
private:
	Registro user;
public:
	GestorClases(const Registro& usuario);
    void run();
    Registro getUser();
};

#endif
