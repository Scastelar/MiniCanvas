#include "Login.h"
#include "Registro.h"
#include "Cuentas.h"
#include "AgregarUsuario.h"
#include <iostream>

Registro::Registro(const string& tipo,const string& user,const string& pass)
		: Usuario(tipo,user,pass){
		}

void Registro::run() {
	
//	Registro usuarioActual(tipo,user,pass);
    Cuentas gestorCuentas("usuarios.txt");
	
    sf::RenderWindow window(sf::VideoMode(800, 500), "Login");
    
 

    // imagen de fondo
    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("fondo1.png")) {
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
    sf::Text tituloTxt(titulo, font, 20);
	tituloTxt.setPosition(295, 150);
	tituloTxt.setFillColor(sf::Color::Black);
 
	
    sf::Text textoError("", font, 20);
	textoError.setPosition(240, 380);
	textoError.setFillColor(sf::Color::Red);
	
    

    // Botones
    //Opciones de Usuario
    sf::RectangleShape addUserButton(sf::Vector2f(170, 40));
    addUserButton.setPosition(100, 250);
    addUserButton.setFillColor(sf::Color::Cyan);
    sf::Text addUserTxt("Agregar Usuario", font, 18);
    addUserTxt.setPosition(112, 257);

	 sf::RectangleShape editUserButton(sf::Vector2f(170, 40));
    editUserButton.setPosition(100, 300);
    editUserButton.setFillColor(sf::Color::Cyan);
    sf::Text editUserTxt("Editar Usuario", font, 18);
    editUserTxt.setPosition(112, 307);
    
    sf::RectangleShape delUserButton(sf::Vector2f(170, 40));
    delUserButton.setPosition(100, 350);
    delUserButton.setFillColor(sf::Color::Cyan);
    sf::Text delUserTxt("Eliminar Usuario", font, 18);
    delUserTxt.setPosition(112, 357);
    
    //Opciones de Clase
	sf::RectangleShape addClassButton(sf::Vector2f(170, 40));
    addClassButton.setPosition(315, 250);
    addClassButton.setFillColor(sf::Color::Magenta);
    sf::Text addClassTxt("Agregar Clase", font, 18);
    addClassTxt.setPosition(327, 257);

	 sf::RectangleShape editClassButton(sf::Vector2f(170, 40));
    editClassButton.setPosition(315, 300);
    editClassButton.setFillColor(sf::Color::Magenta);
    sf::Text editClassTxt("Editar Clase", font, 18);
    editClassTxt.setPosition(327, 307);
    
    sf::RectangleShape delClassButton(sf::Vector2f(170, 40));
    delClassButton.setPosition(315, 350);
    delClassButton.setFillColor(sf::Color::Magenta);
    sf::Text delClassTxt("Eliminar Clase", font, 18);
    delClassTxt.setPosition(327, 357);
    
    //Opciones extra
	sf::RectangleShape asignarMaestro(sf::Vector2f(170, 40));
    asignarMaestro.setPosition(530, 250);
    asignarMaestro.setFillColor(sf::Color::Green);
    sf::Text asignarMaestroTxt("Asignar Maestro", font, 18);
    asignarMaestroTxt.setPosition(542, 257);

	 sf::RectangleShape asignarAlumno(sf::Vector2f(170, 40));
    asignarAlumno.setPosition(530, 300);
    asignarAlumno.setFillColor(sf::Color::Green);
    sf::Text asignarAlumnoTxt("Asignar Alumno", font, 18);
    asignarAlumnoTxt.setPosition(542, 307);
    
    sf::RectangleShape logoutButton(sf::Vector2f(170, 40));
    logoutButton.setPosition(530, 350);
    logoutButton.setFillColor(sf::Color::Red);
    sf::Text logoutTxt("Cerrar Sesion", font, 18);
    logoutTxt.setPosition(542, 357);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)
            window.close();
            

            // Manejo de botones
            if (event.type == sf::Event::MouseButtonPressed) {
             
            if (addUserButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  
                    AgregarUsuario window;
                    window.run();
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
        window.draw(addUserButton);
        window.draw(addUserTxt);
        window.draw(editUserButton);
        window.draw(editUserTxt);
        window.draw(delUserButton);
        window.draw(delUserTxt);
        window.draw(addClassButton);
        window.draw(addClassTxt);
        window.draw(editClassButton);
        window.draw(editClassTxt);
        window.draw(delClassButton);
        window.draw(delClassTxt);
        window.draw(asignarMaestro);
        window.draw(asignarMaestroTxt);
        window.draw(asignarAlumno);
        window.draw(asignarAlumnoTxt);
        window.draw(logoutButton);
        window.draw(logoutTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}

