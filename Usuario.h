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
		
		void setUser(string username){
			user=username;
		}
		
		void setPassword(string pass){
			password=pass;
		}
		
		bool validarContrasena(const string& pass) const;
    		
	};

#endif
