#include "Cuentas.h"

using namespace std;

		string Cuentas::toLowerCase(const std::string& str) {
   		 string lowerStr = str;
    	 transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    		return lowerStr;
		}

		bool Cuentas::isUsuarioUnico(const string& user){
			vector<Usuario> usuarios;
    		leerUsuarios(usuarios);
    
    		string lowerUser = toLowerCase(user);

		    for (const auto& u : usuarios) {
		        if (toLowerCase(u.getUser()) == lowerUser) {
		            return false; // Usuario ya existe
		        }
		    }
		    return true; 	
		}
		
		
		void Cuentas::escribirUsuario(const Usuario& usuario){
			ofstream outFile(archivo, ios::app);
		    if (outFile.is_open()) {
		        outFile << usuario.getTipo() << " " << usuario.getUser() << " " << usuario.getPassword() << "\n";
		        outFile.close();
		    } else {
		        std::cerr << "Error al abrir el archivo para escritura.\n";
		    }
		}
		
		
	    void Cuentas::leerUsuarios(vector<Usuario>& usuarios){
	    	 ifstream inFile(archivo);
		    if (inFile.is_open()) {
		        string tipo, nombre, contrasena;
		        while (inFile >> tipo >> nombre >> contrasena) {
		            usuarios.emplace_back(tipo,nombre, contrasena);
		        }
		        inFile.close();
		    } else {
		        std::cerr << "Error al abrir el archivo para lectura.\n";
		    }
		}
    	
    	bool Cuentas::iniciarSesion(const string nombreUsuario, const string contrasena) {
		    vector<Usuario> usuarios;
		    leerUsuarios(usuarios);

		    for (const auto& u : usuarios) {
		        if (toLowerCase(u.getUser()) == toLowerCase(nombreUsuario) && u.validarContrasena(contrasena)) {
		            return true; 
		        }
		    }
		    return false; 
		}	
		
		void Cuentas::crearUsuario(string tipo,string nombre, string contrasena){
	    	if (!isUsuarioUnico(nombre)) {
		        cout << "El nombre de usuario ya existe. Intente nuevamente.\n";
		        return;
	    	}
		    Usuario nuevoUsuario(tipo,nombre, contrasena);
		    escribirUsuario(nuevoUsuario);
		    cout << "Usuario registrado con éxito.\n";
		}

