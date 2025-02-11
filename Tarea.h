#ifndef TAREA_H
#define TAREA_H

#include <iostream>
#include <fstream>
#include <string>
#include "Alumno.h"

using namespace std;

class Tarea {
	private:
		string nombre;
		int prioridad;
		int puntos;
		bool estado;
	public:
    	Tarea(string nombres, int _puntos,int _prioridad) :
    		nombre(nombres),puntos(_puntos),prioridad(_prioridad){
		}
		
		string getNombre();
		int getPrioridad();
		bool getEstado();
		
		int getPuntos();

	    void guardarTarea();
		/*
		void crearPregunta(int cantidad);
		void calificar();
		void verResultados();
		bool verRespuestas();
		*/		
	};

#endif
