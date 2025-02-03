#ifndef REGISTRO_H
#define REGISTRO_H

#include "Usuario.h"
#include <string>

using namespace std;

class Registro : public Usuario{
	public:
		//constructor
		Registro(const string& tipo,const string& user,const string& pass);
	   
	    void run(); 
};

#endif
