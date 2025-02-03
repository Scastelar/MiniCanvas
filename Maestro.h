#ifndef MAESTRO_H
#define MAESTRO_H

#include "Usuario.h"
#include <string>
using namespace std;

class Maestro : public Usuario{
	private:
		double salario;
	public:
		Maestro(const string& tipo,const string& user,const string& pass);
		
		
		double getSalario() const;
		
		void run(); 
		//void crearExamen(string nombre);
		//void modificarExamen(Examen examen);
		//void eliminarExamen(Examen examen);
		//void agregarTarea(string desc, int prioridad,string fecha,bool estado);
		
};

#endif
