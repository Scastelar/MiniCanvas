#pragma once
#ifndef DOCENTE_H
#define DOCENTE_H

#include <string>
using namespace std;

class Docente {
private:
	string nombre;
	string apellido;
	string correo;
	string password;
public:
	Docente(const string& correoE,const string& pass)
		: correo(correoE),password(pass){}
};

#endif