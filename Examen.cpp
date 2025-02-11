#include "Examen.h"
using namespace std;

		Examen::Examen(string nombres, int _puntos) :
    		nombre(nombres),puntos(_puntos){
		}
  	
		string Examen::getNombre(){
			return nombre;
		}	
			 
		
		int Examen::getPuntos(){
			return puntos;
		}
		
		bool Examen::getEstado(){
			return estado;
		}
		
    	void Examen::agregarPregunta(string pregunta) {
    	    preguntas.push_back(pregunta);
   		}
   		
	   	void Examen::guardarExamen() {
	        ofstream archivo(nombre + "_examen.txt");
	        archivo << nombre << "," << puntos << "\n";
	        for (const auto& p : preguntas) {
	            archivo << p << "\n";
	        }
	        archivo.close();
	    }
		
		//void Examen::calificar();
		//void Examen::verResultados();
		//bool Examen::verRespuestas();	


