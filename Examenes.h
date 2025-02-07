#ifndef EXAMENES_H
#define EXAMENES_H

#include <SFML/Graphics.hpp>
#include "ComboBox.h"
#include "Alumno.h"

class Examenes {
private:
	Alumno user;
public:
	Examenes(const Alumno& usuario);
    void run();
    Alumno getUser();
};

#endif
