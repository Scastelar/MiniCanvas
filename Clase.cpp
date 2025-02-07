#ifndef CLASE_H
#define CLASE_H

#include <string>
#include "Maestro.h"
#include "Alumno.h"

using namespace std;

class Clase {
	private:
		string nombre;
		Maestro maestro;
		vector<Alumno> alumnos;
	public:
    	Clase(const string& nombre, Maestro maestro, vector<Alumno> alumnos);
		string getTipo() const;
		
		string getUser() const;
		
		string getPassword() const;
		
		bool validarContrasena(const string& pass) const;
    		
	};

#endif
