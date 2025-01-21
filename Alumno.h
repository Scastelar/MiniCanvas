#pragma once
#pragma once
#ifndef ALUMNO_H
#define ALUMNO_H

#include <string>
using namespace std;

class Alumno {
private:
	string nombre;
	string apellido;
	string correo;
	string password;
public:
	Alumno(const string& correoE, const string& pass)
		: correo(correoE), password(pass) {}
};

#endif