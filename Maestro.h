#ifndef MAESTRO_H
#define MAESTRO_H

#include "Usuario.h"
#include "Examen.h"
#include "Tarea.h"
#include <string>
using namespace std;

class Maestro : public Usuario{
	private:
		double salario=0;
	public:
		Maestro(const string& tipo,const string& user,const string& pass);
		
		
		double getSalario() const;
		
		void run(); 
		void crearExamen(string nombre,int puntos,int preguntas);
		void modificarExamen(Examen examen);
		void eliminarExamen(Examen examen);
		void crearTarea(string nombre,int puntos,int preguntas);
		
};

#endif
