#ifndef REGISTRO_H
#define REGISTRO_H

#include "Usuario.h"
#include "Clase.h"
#include "Cuentas.h"
#include <string>


using namespace std;

class Registro : public Usuario{
	private:
		string archivo;
		vector<Clase> clases;
	public:
		//constructor
		Registro(const string& tipo,const string& user,const string& pass);
  
	    void run(); 
	    string LowerCase(const std::string& str);
		void leerClases(vector<Clase>& clases);
	    void crearClase(int id, string& nombre, Maestro& profesor);
	    void editarClase(Clase clase);
	    void eliminarClase(const string& nombre);
	    void agregarRegistro();
		void eliminarRegistro();
		void editarUsuario();


};

#endif
