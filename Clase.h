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
		int puntos;
		bool estado;
	public:
    	Clase(string& nombre, Maestro& maestro, vector<Alumno>& alumnos);
		string getNombre() ;
				 
		Maestro getMaestro() ;
		
		vector<Alumno> getAlumnos() ;
		
		void asignarAlumno(Alumno alumno){
			alumnos.push_back(alumno);
		}
		
		void asignarMaestro(Maestro docente){
			maestro=docente;
		}
		
    		
	};

#endif
