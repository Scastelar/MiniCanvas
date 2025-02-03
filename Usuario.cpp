#include "Usuario.h"
using namespace std;

	Usuario::Usuario(const string& type, const string& username, const string& pass)
    : tipo(type), user(username), password(pass) {
	}
    
    
	string Usuario::getTipo() const{
			return tipo;
		}
		
		string Usuario::getUser() const{
			return user;
		}
		
		string Usuario::getPassword() const{
			return password;
		}
		
		bool Usuario::validarContrasena(const string& pass) const {
        	return password == pass;
    	}
