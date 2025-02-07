#ifndef EXAMEN_h
#define EXAMEN_h

#include <string>
#include "Clase.h"
#include "Alumno.h"

using namespace std;

class Examen {
	private:
		string nombre;
		Clase clase;
		int puntos;
		bool estado;
	public:
    	Examen(string& nombre, Clase& clase, int puntos, bool estado);
		
		string getNombre(){
			return nombre;
		}	
			 
		Clase getClase(){
			return clase;
		}
		
		int getPuntos(){
			return puntos;
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
