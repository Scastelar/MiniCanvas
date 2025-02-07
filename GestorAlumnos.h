#ifndef GESTOR_ALUMNOS_H
#define GESTOR_ALUMNOS_H

#include <SFML/Graphics.hpp>
#include "ComboBox.h"
#include "Registro.h"


class GestorAlumnos {
private:
	Registro user;
public:
	GestorAlumnos(const Registro& usuario);
    void run();
    Registro getUser();
};

#endif
