#ifndef CUENTAS_H
#define CUENTAS_H

#include "Usuario.h"
#include "Maestro.h"
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include  <cctype>
using namespace std;

class Cuentas {
	private:
	string archivo;
	
	public:
		Cuentas(const string& archivoNombre)
		: archivo(archivoNombre){
		}
		
		//metodos
		string toLowerCase(const std::string& str);
		bool isUsuarioUnico(const string& user);
		void escribirUsuario(const Usuario& usuario);
	    void leerUsuarios(vector<Usuario>& usuarios);
	    void leerMaestros(vector<Maestro>& usuarios);
	    void leerAlumnos(vector<Alumno>& alumnos);
    	bool iniciarSesion(const string nombreUsuario, const string contrasena);
		void crearUsuario(string tipo,string nombre, string contrasena);
		void eliminarUsuario(const string& nombre);
		void editarUsuario(const string& nombre, const string& nuevoNombre, const string& nuevaContrasena);
};

#endif
