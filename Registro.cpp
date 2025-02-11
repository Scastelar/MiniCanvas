#include "Login.h"
#include "Registro.h"
#include "GestorMaestros.h"
#include "GestorAlumnos.h"
#include "GestorClases.h"
#include "Asignacion.h"
#include "AgregarUsuario.h"
#include <iostream>
#include <sstream>


Registro::Registro(const string& tipo,const string& user,const string& pass)
		: Usuario(tipo,user,pass){
		}
		
		string Registro::LowerCase(const std::string& str) {
   		 string lowerStr = str;
    	 transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    		return lowerStr;
		}
		

		
void Registro::crearClase(string& nombre, Maestro& profesor) {
    Clase nuevaClase(nombre, profesor);
    clases.push_back(nuevaClase);

    ofstream archivo("clases.txt", ios::app);
    
    if (!archivo) {
        cout << "Error al abrir el archivo de clases.\n";
        return;
    }

    archivo << nombre << "," << profesor.getUser() << "\n";
    
    archivo.close();
}

void Registro::leerClases(vector<Clase>& clases) {
    ifstream archivo("clases.txt");
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo de clases.\n";
        return;
    }

    string linea;
    while (getline(archivo, linea)) {
        // Suponemos que cada línea tiene el formato: nombreClase,nombreMaestro
        size_t pos = linea.find(',');
        if (pos != string::npos) {
            string nombreClase = linea.substr(0, pos);
            string nombreMaestro = linea.substr(pos + 1);

            // Aquí deberías crear un objeto Maestro usando el nombre del maestro
            Maestro maestro("tipo", nombreMaestro, "pass"); // Asigna valores por defecto o ajusta según tu lógica

            // Crear una nueva clase y agregarla al vector
            Clase nuevaClase(nombreClase, maestro);
            clases.push_back(nuevaClase);
        }
    }

    archivo.close();
}
		
void Registro::eliminarClase(const string& nombreClase) {
    vector<Clase> clases;
    leerClases(clases); // Primero, lee todas las clases

    ofstream archivo("clases.txt", ios::trunc); // Abre el archivo en modo truncado para reescribirlo
    if (!archivo.is_open()) {
        cerr << "Error al abrir el archivo para eliminar la clase.\n";
        return;
    }

    for (const auto& clase : clases) {
        if (clase.getNombre() != nombreClase) {
            archivo << clase.getNombre() << "," << clase.getMaestro().getUser() << endl; // Escribe las clases que no se eliminan
        }
    }

    archivo.close();
}


void Registro::run() {
	
	Registro usuarioActual(this->getTipo(),this->getUser(),this->getPassword());
    Cuentas gestorCuentas("usuarios.txt");
	
    sf::RenderWindow window(sf::VideoMode(800, 500), "Acceso");
    
 

    // imagen de fondo
    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("fondo2.png")) {
        std::cerr << "Error al cargar la imagen de fondo." << std::endl;
        return;
    }
    sf::Sprite fondo(fondoTexture);

    // textos
    sf::Font font;
    if (!font.loadFromFile("consola.ttf")) {
        std::cerr << "Error al cargar la fuente." << std::endl;
        return;
    }
    
	std::string titulo = "Bienvenido, " + this->getUser() + "!";
    sf::Text tituloTxt(titulo, font, 28);
	tituloTxt.setPosition(295, 70);
	tituloTxt.setFillColor(sf::Color::Black);
 
	
    sf::Text textoError("", font, 20);
	textoError.setPosition(240, 380);
	textoError.setFillColor(sf::Color(171, 97, 169));
	
    

   
    //Texturas
	sf::Texture accesoT;
    if (!accesoT.loadFromFile("access-control.png")) {  
        std::cerr << "Error al cargar la imagen\n";
        return;
    }
    sf::Texture maestroT;
    if (!maestroT.loadFromFile("school.png")) {  
        std::cerr << "Error al cargar la imagen\n";
        return;
    }
    sf::Texture alumnoT;
    if (!alumnoT.loadFromFile("graduation.png")) {  
        std::cerr << "Error al cargar la imagen\n";
        return;
    }
    sf::Texture claseT;
    if (!claseT.loadFromFile("knowledge.png")) {  
        std::cerr << "Error al cargar la imagen\n";
        return;
    }
    sf::Texture assignT;
    if (!assignT.loadFromFile("user.png")) {  
        std::cerr << "Error al cargar la imagen\n";
        return;
    }

	 // Botones
    sf::Sprite accessButton;
    accessButton.setTexture(accesoT);
    accessButton.setPosition(37, 20); 
    
    sf::Sprite maestroButton;
    maestroButton.setTexture(maestroT);
    maestroButton.setPosition(32, 120); 
    
    sf::Sprite alumnoButton;
    alumnoButton.setTexture(alumnoT);
    alumnoButton.setPosition(32, 200); 
    
    sf::Sprite claseButton;
    claseButton.setTexture(claseT);
    claseButton.setPosition(32, 280); 
    
    sf::Sprite asignarButton;
    asignarButton.setTexture(assignT);
    asignarButton.setPosition(32, 360); 
    
    sf::RectangleShape addUserButton(sf::Vector2f(170, 40));
    addUserButton.setPosition(295, 200);
    addUserButton.setFillColor(sf::Color(171, 97, 169));
    sf::Text addUserTxt("Agregar Usuario", font, 18);
    addUserTxt.setPosition(307, 207);
    
      sf::RectangleShape delUser(sf::Vector2f(170, 40));
    delUser.setPosition(295, 300);
    delUser.setFillColor(sf::Color(171, 97, 169));
    sf::Text delUserTxt("Eliminar Usuario", font, 18);
    delUserTxt.setPosition(303, 307);
    
    sf::RectangleShape logoutButton(sf::Vector2f(170, 40));
    logoutButton.setPosition(500, 300);
    logoutButton.setFillColor(sf::Color::Red);
    sf::Text logoutTxt("Cerrar Sesion", font, 18);
    logoutTxt.setPosition(512, 307);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)
            window.close();
            

            // Manejo de botones
            if (event.type == sf::Event::MouseButtonPressed) {
            	
            	if (maestroButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorMaestros maestros(usuarioActual);
                    maestros.run();
                } 
                
                if (alumnoButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorAlumnos alumnos(usuarioActual);
                    alumnos.run();
            } 
            
             if (asignarButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Asignacion asignar(usuarioActual);
                    asignar.run();
            }
            
            if (claseButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorClases alumnos(usuarioActual);
                    alumnos.run();
            } 
             
            if (addUserButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  agregarRegistro();
                  //textoError.setString("Usuario agregado!");
            } 
                
            if (delUser.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                eliminarRegistro();
				//textoError.setString("Usuario eliminado.");   
            } 
             
            if (logoutButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                   window.close(); 
                    Login window;
                    window.run();
                    return;
                }
            
        }
    }
        

        window.clear();
        window.draw(fondo);
        window.draw(tituloTxt);
        window.draw(accessButton);
        window.draw(maestroButton);
        window.draw(alumnoButton);
        window.draw(claseButton);
        window.draw(asignarButton);
        window.draw(addUserButton);window.draw(addUserTxt);
        window.draw(delUser);window.draw(delUserTxt);
        window.draw(logoutButton);window.draw(logoutTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}


void Registro::agregarRegistro(){
	Cuentas gestorCuentas("usuarios.txt");
	sf::RenderWindow addWindow(sf::VideoMode(300, 350), "Agregar Usuario");
	sf::Font font;
	font.loadFromFile("consola.ttf");
	
	sf::Text titulo("Crear Registro", font, 24); 
	titulo.setPosition(50, 20);
	titulo.setFillColor(sf::Color::Black);

	sf::Text userTxt("Usuario:", font, 20); 
	userTxt.setPosition(50, 70);
	userTxt.setFillColor(sf::Color::Black);
	
	sf::RectangleShape campoUser ({200, 30});
	campoUser.setPosition(50, 110);
	campoUser.setFillColor(sf::Color::White);
	campoUser.setOutlineColor(sf::Color::Black);
	campoUser.setOutlineThickness(2);
	
	sf::Text textoInputUsuario("", font, 20);
	textoInputUsuario.setPosition(50, 110); 
	textoInputUsuario.setFillColor(sf::Color::Black);
	
	sf::Text passTxt("Contrasena:", font, 20); 
	passTxt.setPosition(50, 160);
	passTxt.setFillColor(sf::Color::Black);
		
	sf::RectangleShape campoPass({200, 30});
	campoPass.setPosition(50, 200); 
	campoPass.setFillColor(sf::Color::White);
	campoPass.setOutlineColor(sf::Color::Black);
	campoPass.setOutlineThickness(2);
		
	sf::Text textoInputContrasena("", font, 20);
	textoInputContrasena.setPosition(50, 200); 
	textoInputContrasena.setFillColor(sf::Color::Black);
	
	sf::RectangleShape boton({200, 40});
	boton.setPosition(50, 260); 
	boton.setFillColor(sf::Color::Black);
	
	sf::Text textoBoton("Agregar", font, 20);
	textoBoton.setPosition(115, 270); 
	textoBoton.setFillColor(sf::Color::White);
    
    sf::Text textoError("", font, 20);
    textoError.setPosition(20, 310);
    textoError.setFillColor(sf::Color::Red);
    
    // focus en textos
    bool focoUsuario = false;
    bool focoContrasena = false;
    std::string contrasenaReal;

    while (addWindow.isOpen()) {
        sf::Event event;
        while (addWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                addWindow.close();
            
            if (event.type == sf::Event::MouseButtonPressed) {
                focoUsuario = campoUser .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
                focoContrasena = campoPass.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
            }
            
            // Captura el texto ingresado
            if (event.type == sf::Event::TextEntered) {
                if (focoUsuario) {
                    if (event.text.unicode == '\b' && !textoInputUsuario.getString().isEmpty()) {
                        std::string str = textoInputUsuario.getString();
                        str.pop_back();
                        textoInputUsuario.setString(str);
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                        textoInputUsuario.setString(textoInputUsuario.getString() + static_cast<char>(event.text.unicode));
                    }
                } else if (focoContrasena) {
                    if (event.text.unicode == '\b' && !contrasenaReal.empty()) {
                        contrasenaReal.pop_back(); // Elimina el último carácter real
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                        contrasenaReal += static_cast<char>(event.text.unicode); // Agrega el carácter real
                    }

                    // Actualiza el texto mostrado con asteriscos
                    textoInputContrasena.setString(std::string(contrasenaReal.size(), '*'));
                }
            }
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (boton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    if (textoInputUsuario.getString().isEmpty() || textoInputContrasena.getString().isEmpty()) {
                        textoError.setString("Por favor, complete ambos campos.");
                    } else if (!gestorCuentas.isUsuarioUnico(textoInputUsuario.getString().toAnsiString())) {
                        textoError.setString("Usuario ya existente.");
                    } else {
                        // Cambiar el tipo a "REGISTRO"
                        gestorCuentas.crearUsuario("REGISTRO", textoInputUsuario.getString().toAnsiString(), contrasenaReal);
                        addWindow.close();
                    }
                }
            }
        }
        
        addWindow.clear(sf::Color::White);
        addWindow.draw(titulo);
        addWindow.draw(passTxt);
        addWindow.draw(userTxt);
        addWindow.draw(campoUser );
        addWindow.draw(campoPass);
        addWindow.draw(textoInputUsuario);
        addWindow.draw(textoInputContrasena);
        addWindow.draw(boton);
        addWindow.draw(textoBoton);
        if (!textoError.getString().isEmpty()) {
            addWindow.draw(textoError);
        }
        addWindow.display();
    }
}

void Registro::eliminarRegistro(){
	Cuentas gestorCuentas("usuarios.txt");
	sf::RenderWindow addWindow(sf::VideoMode(300, 350), "Eliminar Clase");
	sf::Font font;
	font.loadFromFile("consola.ttf");
	
	sf::Text titulo("Eliminar Registro", font, 24); 
	titulo.setPosition(50, 20);
	titulo.setFillColor(sf::Color::Black);

	sf::Text userTxt("Usuario a eliminar:", font, 20); 
	userTxt.setPosition(50, 70);
	userTxt.setFillColor(sf::Color::Black);
	
	sf::RectangleShape campoUser ({200, 30});
	campoUser.setPosition(50, 110);
	campoUser.setFillColor(sf::Color::White);
	campoUser.setOutlineColor(sf::Color::Black);
	campoUser.setOutlineThickness(2);
	
		sf::Text textoInputUsuario("", font, 20);
	textoInputUsuario.setPosition(50, 110); 
	textoInputUsuario.setFillColor(sf::Color::Black);
	
	sf::RectangleShape boton({200, 40});
	boton.setPosition(50, 260); 
	boton.setFillColor(sf::Color::Black);
	
	sf::Text textoBoton("Eliminar", font, 20);
	textoBoton.setPosition(115, 270); 
	textoBoton.setFillColor(sf::Color::White);
    
    sf::Text textoError("", font, 20);
    textoError.setPosition(20, 310);
    textoError.setFillColor(sf::Color::Red);
    bool focoUsuario = false;


    while (addWindow.isOpen()) {
        sf::Event event;
        while (addWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                addWindow.close();
            
            if (event.type == sf::Event::MouseButtonPressed) {
                focoUsuario = campoUser .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
            }
            
            if (event.type == sf::Event::TextEntered) {
                if (focoUsuario) {
                    if (event.text.unicode == '\b' && !textoInputUsuario.getString().isEmpty()) {
                        std::string str = textoInputUsuario.getString();
                        str.pop_back();
                        textoInputUsuario.setString(str);
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                        textoInputUsuario.setString(textoInputUsuario.getString() + static_cast<char>(event.text.unicode));
                    }
                } 
            }
            
            std::string usuarioActual = textoInputUsuario.getString();
            
                	std::string type = "REGISTRO";
                	//Usuario userActual;
                	vector <Usuario> usuarios;
					gestorCuentas.leerUsuarios(usuarios);
					
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (boton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						
                    if (textoInputUsuario.getString().isEmpty()) {
                        textoError.setString("Por favor, complete el campo.");
                    } else if (gestorCuentas.isUsuarioUnico(textoInputUsuario.getString().toAnsiString())) {
                        textoError.setString("Usuario no existente.");
                    } 
                    
                    for (Usuario user:usuarios){
                      	if (user.getUser()==usuarioActual && user.getTipo()==type){
                        	gestorCuentas.eliminarUsuario(textoInputUsuario.getString().toAnsiString());
                        	addWindow.close();
                    	} else {
                    		textoError.setString("Usuario no es Registro.");
						}
					}
                        
                
                }
            }
        }
        
        addWindow.clear(sf::Color::White);
        addWindow.draw(titulo);
        addWindow.draw(userTxt);
        addWindow.draw(campoUser );
        addWindow.draw(textoInputUsuario);
        addWindow.draw(boton);
        addWindow.draw(textoBoton);
        if (!textoError.getString().isEmpty()) {
            addWindow.draw(textoError);
        }
        addWindow.display();
    }
}

