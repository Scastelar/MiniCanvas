#ifndef EXAMEN_H
#define EXAMEN_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Alumno.h"

using namespace std;

class Examen {
	private:
		string nombre;
		int puntos;
		int duracion;
		vector<string> preguntas;
		vector<string> respuestas;
		bool estado=true;
	public:
    	Examen(string nombres, int _puntos);
		
		string getNombre();
			 
		
		int getPuntos();
		
		bool getEstado();
    	void agregarPregunta(string pregunta);
	   	void guardarExamen() ;
		
		//void calificar();
		//void verResultados();
		//bool verRespuestas();		
	};

#endif
