#include "GestorMaestros.h"
#include "GestorAlumnos.h"
#include "GestorClases.h"
#include "Asignacion.h"
#include "Cuentas.h"

	GestorMaestros::GestorMaestros(const Registro& usuario):
		user(usuario){
		}

	Registro GestorMaestros::getUser(){
		return user;
	}
	
	void agregarMaestro();
	void eliminarMaestro();
	void editarMaestro();

    void GestorMaestros::run() {	
	Registro usuarioActual(this->getUser());
    Cuentas gestorCuentas("usuarios.txt");
	
    sf::RenderWindow window(sf::VideoMode(800, 500), "Maestros");
    
 	

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
    
 	std::string s = "Administracion de Maestros";
    sf::Text titulo(s, font, 28);
	titulo.setPosition(295, 70);
	titulo.setFillColor(sf::Color::Black);
	
    sf::Text textoError("", font, 20);
	textoError.setPosition(240, 380);
	textoError.setFillColor(sf::Color::Red);
	
    

   
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
    sf::Text addUserTxt("Agregar Maestro", font, 18);
    addUserTxt.setPosition(307, 207);
    
      sf::RectangleShape editUser(sf::Vector2f(170, 40));
    editUser.setPosition(295, 300);
    editUser.setFillColor(sf::Color(171, 97, 169));
    sf::Text editUserTxt("Editar Maestro", font, 18);
    editUserTxt.setPosition(303, 307);
    
    sf::RectangleShape delUser(sf::Vector2f(170, 40));
    delUser.setPosition(500, 300);
    delUser.setFillColor(sf::Color::Red);
    sf::Text delUserTxt("Eliminar Maestro", font, 18);
    delUserTxt.setPosition(512, 307);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)
            window.close();
            

            // Manejo de botones
            if (event.type == sf::Event::MouseButtonPressed) {
             
              if (accessButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Registro acceso(this->getUser());
                    acceso.run();
                } 
                
            if (alumnoButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorAlumnos alumnos(this->getUser());
                    alumnos.run();
            } 
            
             if (asignarButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Asignacion asignar(this->getUser());
                    asignar.run();
            }
            
            if (claseButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorClases alumnos(this->getUser());
                    alumnos.run();
            } 
            
             if (addUserButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            	agregarMaestro();                      
            } 
            
            if (delUser.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            	eliminarMaestro();                      
            } 
            
        }
    }
        

        window.clear();
        window.draw(fondo);
        window.draw(titulo);
        window.draw(accessButton);
        window.draw(maestroButton);
        window.draw(alumnoButton);
        window.draw(claseButton);
        window.draw(asignarButton);
        window.draw(addUserButton);window.draw(addUserTxt);
        window.draw(delUser);window.draw(delUserTxt);
        window.draw(editUser);window.draw(editUserTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}

void agregarMaestro(){
	Cuentas gestorCuentas("usuarios.txt");
	sf::RenderWindow addWindow(sf::VideoMode(300, 350), "Agregar Usuario");
	sf::Font font;
	font.loadFromFile("consola.ttf");
	
	sf::Text titulo("Crear Maestro", font, 24); 
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
                        gestorCuentas.crearUsuario("MAESTRO", textoInputUsuario.getString().toAnsiString(), contrasenaReal);
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

void eliminarMaestro(){
	Cuentas gestorCuentas("usuarios.txt");
	sf::RenderWindow addWindow(sf::VideoMode(300, 350), "Eliminar Usuario");
	sf::Font font;
	font.loadFromFile("consola.ttf");
	
	sf::Text titulo("Eliminar Maestro", font, 24); 
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
            
                	std::string type = "MAESTRO";
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
                    		textoError.setString("Usuario no es Maestro.");
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
