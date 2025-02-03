#include "AgregarUsuario.h"
#include "Cuentas.h"
#include "ComboBox.h"
#include "Registro.h"


    void AgregarUsuario::run() {
    	
    	Cuentas gestorCuentas("usuarios.txt");
    	
        sf::RenderWindow addWindow(sf::VideoMode(300, 350), "Agregar Usuario");
        sf::Font font;
        font.loadFromFile("consola.ttf");
        
        ComboBox combo(50, 150, {"REGISTRO", "MAESTRO", "ALUMNO"});
        
        sf::RectangleShape campoUser({200, 30});
        campoUser.setPosition(50, 50);
        campoUser.setFillColor(sf::Color::White);
        campoUser.setOutlineColor(sf::Color::Black);
        campoUser.setOutlineThickness(2);
        
        sf::RectangleShape campoPass({200, 30});
        campoPass.setPosition(50, 100);
        campoPass.setFillColor(sf::Color::White);
        campoPass.setOutlineColor(sf::Color::Black);
        campoPass.setOutlineThickness(2);
        
        sf::Text textoInputUsuario("", font, 20);
	    textoInputUsuario.setPosition(50, 50);
	    textoInputUsuario.setFillColor(sf::Color::Black);
	
	    sf::Text textoInputContrasena("", font, 20);
	    textoInputContrasena.setPosition(50, 100);
	    textoInputContrasena.setFillColor(sf::Color::Black);
        
        sf::RectangleShape boton({200, 40});
        boton.setPosition(50, 300);
        boton.setFillColor(sf::Color::Black);
        
        sf::Text textoBoton("Agregar", font, 20);
        textoBoton.setPosition(115, 305);
        textoBoton.setFillColor(sf::Color::White);
        
        sf::Text textoError("", font, 20);
		textoError.setPosition(130, 335);
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
        combo.handleEvent(event, addWindow);
                
        if (event.type == sf::Event::MouseButtonPressed) {
            	
            focoUsuario = campoUser.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
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
                    contrasenaReal.pop_back(); // Elimina el ultimo caracter real
                } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    contrasenaReal += static_cast<char>(event.text.unicode); // Agrega el caracter real
                }

                // Actualiza el texto mostrado con asteriscos
                textoInputContrasena.setString(std::string(contrasenaReal.size(), '*'));
            }
        }
        
            
        if (event.type == sf::Event::MouseButtonPressed) {
            	
            focoUsuario = campoUser.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
            focoContrasena = campoPass.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
             
            if (boton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  
                    if (textoInputUsuario.getString().isEmpty() || textoInputContrasena.getString().isEmpty()) {
			    textoError.setString("Por favor, complete ambos campos.");
			} else if (!gestorCuentas.isUsuarioUnico(textoInputUsuario.getString().toAnsiString())){
						textoError.setString("Usuario ya existente.");
			}else {
				    gestorCuentas.crearUsuario(combo.getSelectedOption(),textoInputUsuario.getString().toAnsiString(),contrasenaReal);
				        addWindow.close();
				        
                	} 
				}
			}
    	}
    	
            addWindow.clear(sf::Color::White);
            combo.draw(addWindow);
            addWindow.draw(campoUser);
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



