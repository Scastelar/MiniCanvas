#ifndef ASIGNACION_H
#define ASIGNACION_H

#include <SFML/Graphics.hpp>
#include "ComboBox.h"
#include "Registro.h"


class Asignacion {
private:
	Registro user;
public:
	Asignacion(const Registro& usuario);
    void run();
    Registro getUser();
    void assignAlumno();
    void assignMaestro();
};

#endif
