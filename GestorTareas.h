#ifndef GESTOR_TAREAS_H
#define GESTOR_TAREAS_H

#include <SFML/Graphics.hpp>
#include "ComboBox.h"
#include "Maestro.h"

class GestorTareas {
private:
	Maestro user;
public:
	GestorTareas(const Maestro& usuario);
    void run();
    Maestro getUser();
};

#endif
