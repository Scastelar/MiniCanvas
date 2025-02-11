#ifndef ALUMNO_H
#define ALUMNO_H

#include <iostream>
#include <fstream>
#include "Usuario.h"
#include <string>
using namespace std;

class Alumno : public Usuario{
	private:
		string carrera;
		int calificacion=0;
	public:
		Alumno(const string& tipo,const string& user,const string& pass);
		string getCarrera();
		void run(); 
		
		void resolverExamen(string nombreExamen) {
        ifstream archivo(nombreExamen + "_examen.txt");
        if (!archivo.is_open()) {
            cout << "No se pudo abrir el examen.\n";
            return;
        }

        string linea;
        while (getline(archivo, linea)) {
            cout << linea << "\n";
        }
        archivo.close();

    }
};

#endif
