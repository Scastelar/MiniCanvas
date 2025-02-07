#ifndef GESTOR_EXAMENES_H
#define GESTOR_EXAMENES_H

#include <SFML/Graphics.hpp>
#include "ComboBox.h"
#include "Maestro.h"

class GestorExamenes {
private:
	Maestro user;
public:
	GestorExamenes(const Maestro& usuario);
    void run();
    Maestro getUser();
};

#endif
