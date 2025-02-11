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
		
				
		void Cuentas::escribirUsuario(const Usuario& usuario) {
		    ofstream outFile(archivo, ios::app);
		    if (outFile.is_open()) {
		        outFile << usuario.getTipo() << " " 
		                << toLowerCase(usuario.getUser()) << " " 
		                << toLowerCase(usuario.getPassword()) << "\n";
		        outFile.close();
		    } else {
		        cerr << "Error al abrir el archivo para escritura.\n";
		    }
		}
		
		void Cuentas::leerUsuarios(vector<Usuario>& usuarios) {
		    ifstream inFile(archivo);
		    if (inFile.is_open()) {
		        string tipo, nombre, contrasena;
		        while (inFile >> tipo >> nombre >> contrasena) {
		            usuarios.emplace_back(tipo, toLowerCase(nombre), toLowerCase(contrasena));
		        }
		        inFile.close();
		    } else {
		        cerr << "Error al abrir el archivo para lectura.\n";
		    }
		}
		
		void Cuentas::leerMaestros(vector<Maestro>& usuarios) {
		    ifstream inFile(archivo);
		    if (inFile.is_open()) {
		        string tipo, nombre, contrasena;
		        while (inFile >> tipo >> nombre >> contrasena) {
		            usuarios.emplace_back(tipo, toLowerCase(nombre), toLowerCase(contrasena));
		        }
		        inFile.close();
		    } else {
		        cerr << "Error al abrir el archivo para lectura.\n";
		    }
		}
		
		void Cuentas::leerAlumnos(vector<Alumno>& alumnos) {
		    ifstream inFile(archivo);
		    if (inFile.is_open()) {
		        string tipo, nombre, contrasena;
		        while (inFile >> tipo >> nombre >> contrasena) {
		            alumnos.emplace_back(tipo, toLowerCase(nombre), toLowerCase(contrasena));
		        }
		        inFile.close();
		    } else {
		        cerr << "Error al abrir el archivo para lectura.\n";
		    }
		}
		
		bool Cuentas::iniciarSesion(const string nombreUsuario, const string contrasena) {
		    vector<Usuario> usuarios;
		    leerUsuarios(usuarios);
		
		    string lowerUser = toLowerCase(nombreUsuario);
		    string lowerPass = toLowerCase(contrasena);
		
		    for (const auto& u : usuarios) {
		        if (toLowerCase(u.getUser()) == lowerUser && toLowerCase(u.getPassword()) == lowerPass) {
		            return true; 
		        }
		    }
		    return false; 
		}
		
		void Cuentas::crearUsuario(string tipo, string nombre, string contrasena) {
		    string lowerNombre = toLowerCase(nombre);
		    string lowerContrasena = toLowerCase(contrasena);
		
		    if (!isUsuarioUnico(lowerNombre)) {
		        cout << "El nombre de usuario ya existe. Intente nuevamente.\n";
		        return;
		    }
		    Usuario nuevoUsuario(tipo, lowerNombre, lowerContrasena);
		    escribirUsuario(nuevoUsuario);
		    cout << "Usuario registrado con éxito.\n";
		}
		
		void Cuentas::eliminarUsuario(const string& nombre) {
		    vector<Usuario> usuarios;
		    leerUsuarios(usuarios);
		
		    ofstream temp("temp.txt");
		    bool encontrado = false;
		    string lowerNombre = toLowerCase(nombre);
		
		    if (temp.is_open()) {
		        for (const auto& usuario : usuarios) {
		            if (toLowerCase(usuario.getUser()) != lowerNombre) {
		                temp << usuario.getTipo() << " " << usuario.getUser() << " " << usuario.getPassword() << "\n";
		            } else {
		                encontrado = true;
		            }
		        }
		        temp.close();
		        remove(archivo.c_str());
		        rename("temp.txt", archivo.c_str());
		
		        if (encontrado) {
		            cout << "Usuario eliminado con éxito.\n";
		        } else {
		            cout << "Usuario no encontrado.\n";
		        }
		    } else {
		        cerr << "Error al abrir el archivo temporal para escritura.\n";
		    }
		}
		
		void Cuentas::editarUsuario(const string& nombre, const string& nuevoNombre, const string& nuevaContrasena) {
		    vector<Usuario> usuarios;
		    leerUsuarios(usuarios);
		
		    ofstream temp("temp.txt");
		    bool encontrado = false;
		    string lowerNombre = toLowerCase(nombre);
		    string lowerNuevoNombre = toLowerCase(nuevoNombre);
		    string lowerNuevaContrasena = toLowerCase(nuevaContrasena);
		
		    if (temp.is_open()) {
		        for (auto& usuario : usuarios) {
		            if (toLowerCase(usuario.getUser()) == lowerNombre) {
		                usuario.setUser(lowerNuevoNombre);
		                usuario.setPassword(lowerNuevaContrasena);
		                encontrado = true;
		            }
		            temp << usuario.getTipo() << " " << usuario.getUser() << " " << usuario.getPassword() << "\n";
		        }
		        temp.close();
		        remove(archivo.c_str());
		        rename("temp.txt", archivo.c_str());
		
		        if (encontrado) {
		            cout << "Usuario actualizado con éxito.\n";
		        } else {
		            cout << "Usuario no encontrado.\n";
		        }
		    } else {
		        cerr << "Error al abrir el archivo temporal para escritura.\n";
		    }
		}



