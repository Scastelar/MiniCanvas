#ifndef TAREAS_H
#define TAREAS_H

#include <SFML/Graphics.hpp>
#include "ComboBox.h"
#include "Alumno.h"

class Tareas {
private:
	Alumno user;
public:
	Tareas(const Alumno& usuario);
    void run();
    Alumno getUser();
};

#endif
