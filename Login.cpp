#include "Login.h"
#include "Cuentas.h"
#include "Registro.h"
#include "Maestro.h"
#include "Alumno.h"
#include "Usuario.h"
#include <iostream>
using namespace std;

void Login::run() {
	
	Cuentas gestorCuentas("usuarios.txt");
	gestorCuentas.crearUsuario("REGISTRO","Registro","2025");
	
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
    sf::Text textoError("", font, 20);
	textoError.setPosition(240, 380);
	textoError.setFillColor(sf::Color::Red);

    sf::Text textoUsuario("Usuario:", font, 24);
    textoUsuario.setFillColor(sf::Color::Black);
    textoUsuario.setPosition(150, 180);

    sf::Text textoContrasena("Contraseña:", font, 24);
    textoContrasena.setFillColor(sf::Color::Black);
    textoContrasena.setPosition(150, 260);

    // textboxs
    sf::RectangleShape campoUsuario(sf::Vector2f(300, 40));
    campoUsuario.setPosition(300, 180);
    campoUsuario.setFillColor(sf::Color::White);

    sf::RectangleShape campoContrasena(sf::Vector2f(300, 40));
    campoContrasena.setPosition(300, 260);
    campoContrasena.setFillColor(sf::Color::White);

    sf::Text textoInputUsuario("", font, 20);
    textoInputUsuario.setPosition(310, 185);
    textoInputUsuario.setFillColor(sf::Color::Black);

    sf::Text textoInputContrasena("", font, 20);
    textoInputContrasena.setPosition(310, 265);
    textoInputContrasena.setFillColor(sf::Color::Black);

    // Botones
    sf::RectangleShape botonLogin(sf::Vector2f(200, 50));
    botonLogin.setPosition(285, 350);
    botonLogin.setFillColor(sf::Color(171, 97, 169));

    sf::Text textoLogin("Login", font, 24);
    textoLogin.setPosition(350, 360);

    // focus en textos
    bool focoUsuario = false;
    bool focoContrasena = false;

	// Nueva variable para almacenar el texto real de la contrasena
std::string contrasenaReal;

while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();

        // Detecta clicks en los campos de texto
        if (event.type == sf::Event::MouseButtonPressed) {
            focoUsuario = campoUsuario.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
            focoContrasena = campoContrasena.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
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
                    contrasenaReal.pop_back(); // Elimina el ultimo caracter real
                } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    contrasenaReal += static_cast<char>(event.text.unicode); // Agrega el caracter real
                }

                // Actualiza el texto mostrado con asteriscos
                textoInputContrasena.setString(std::string(contrasenaReal.size(), '*'));
            }
        }

        // Manejo de botones
        if (event.type == sf::Event::MouseButtonPressed) {
            // Boton Login
            if (botonLogin.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                if (textoInputUsuario.getString().isEmpty() || contrasenaReal.empty()) {
                    textoError.setString("Por favor, complete ambos campos.");
                } else if (gestorCuentas.iniciarSesion(textoInputUsuario.getString(),contrasenaReal)){
                	std::string usuarioActual = textoInputUsuario.getString();
                	std::string type = "REGISTRO";
                	vector <Usuario> usuarios;
					gestorCuentas.leerUsuarios(usuarios);
					for (Usuario user:usuarios){
						if (user.getTipo()==type && user.getUser()==usuarioActual){
						 window.close();
		                Registro registerWindow(user.getTipo(),user.getUser(),user.getPassword());
		                registerWindow.run();
		                return;
						}
						else if (user.getTipo()=="MAESTRO" && user.getUser()==usuarioActual){
							window.close();
		                Maestro maestroWindow(user.getTipo(),user.getUser(),user.getPassword());
		                maestroWindow.run();
		                return;
						}
						else if (user.getTipo()=="ALUMNO" && user.getUser()==usuarioActual){
							window.close();
		                Alumno alumnoWindow(user.getTipo(),user.getUser(),user.getPassword());
		                alumnoWindow.run();
		                return;
						}
					}
				}
            }	
        }
    }

    window.clear();
    window.draw(fondo);
    window.draw(textoUsuario);
    window.draw(campoUsuario);
    window.draw(textoInputUsuario);
    window.draw(textoContrasena);
    window.draw(campoContrasena);
    window.draw(textoInputContrasena);
    window.draw(botonLogin);
    window.draw(textoLogin);
    if (!textoError.getString().isEmpty()) {
        window.draw(textoError);
    }
    window.display();
}
}



