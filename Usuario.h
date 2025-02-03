#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using namespace std;

class Usuario {
	private:
		string tipo;
		string user;
		string password;
	public:
    	Usuario(const string& type, const string& username, const string& pass);
		string getTipo() const;
		
		string getUser() const;
		
		string getPassword() const;
		
		bool validarContrasena(const string& pass) const;
    		
	};

#endif
