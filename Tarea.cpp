#include "Tarea.h"

using namespace std;

		
		string Tarea::getNombre(){
			return nombre;
		}	
		
		int Tarea::getPrioridad(){
			return prioridad;
		}
		
		bool Tarea::getEstado(){
			return estado;
		}
		
		int Tarea::getPuntos() { 
			return puntos; 
		}

	    void Tarea::guardarTarea() {
	        ofstream archivo("tareas.txt", ios::app);
	        archivo << nombre << "," << puntos << "," << prioridad << "\n";
	        archivo.close();
	    }
		
		//void crearPregunta(int cantidad);
		//void calificar();
		//void verResultados();
		//bool verRespuestas();		
