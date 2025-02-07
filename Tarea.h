#ifndef TAREA_H
#define TAREA_H

#include <string>
#include "Clase.h"
#include "Alumno.h"

using namespace std;

class Examen {
	private:
		string nombre;
		Clase clase;
		int prioridad;
		bool estado;
	public:
    	Examen(string nombre, int prioridad,string fecha,bool estado);
		
		string getNombre(){
			return nombre;
		}	
			 
		Clase getClase(){
			return clase;
		}
		
		int getPrioridad(){
			return prioridad;
		}
		
		bool getEstado(){
			return estado;
		}
		
		void crearPregunta();
		void calificar();
		void verResultados();
		bool verRespuestas();		
	};

#endif
