#ifndef ALUMNO_H
#define ALUMNO_H

#include "Usuario.h"
#include <string>
using namespace std;

class Alumno : public Usuario{
	private:
		string carrera;
	public:
		Alumno(const string& tipo,const string& user,const string& pass);
		string getCarrera();
		void run(); 
};

#endif
