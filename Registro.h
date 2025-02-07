#ifndef REGISTRO_H
#define REGISTRO_H

#include "Usuario.h"
#include "Clase.h"
#include <string>

using namespace std;

class Registro : public Usuario{
	public:
		//constructor
		Registro(const string& tipo,const string& user,const string& pass);
	   
	    void run(); 
	    void crearClase(Clase clase);
	    void editarClase(Clase clase);
	    void eliminarClase(Clase clase);
};

#endif
