#include "GestorAlumnos.h"
#include "GestorMaestros.h"
#include "GestorClases.h"
#include "Asignacion.h"
#include "Cuentas.h"

	GestorClases::GestorClases(Registro usuario):
		user(usuario){
		}

	Registro GestorClases::getUser(){
		return user;
	}

	
	
    void GestorClases::run() {	
	Registro usuarioActual = this->getUser();
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
    
    std::string s = "Administracion de Clases";
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
    
    sf::RectangleShape addClassButton(sf::Vector2f(170, 40));
    addClassButton.setPosition(295, 200);
    addClassButton.setFillColor(sf::Color(171, 97, 169));
    sf::Text addClassTxt("Agregar Clase", font, 18);
    addClassTxt.setPosition(307, 207);
    
    sf::RectangleShape delClaseButton(sf::Vector2f(170, 40));
    delClaseButton.setPosition(500, 300);
    delClaseButton.setFillColor(sf::Color::Red);
    sf::Text delClaseTxt("Eliminar Clase", font, 18);
    delClaseTxt.setPosition(512, 307);
    
    sf::RectangleShape editClaseButton(sf::Vector2f(170, 40));
    editClaseButton.setPosition(295, 300);
    editClaseButton.setFillColor(sf::Color(171, 97, 169));
    sf::Text editClaseTxt("Editar Clase", font, 18);
    editClaseTxt.setPosition(303, 307);

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
                
            if (maestroButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorMaestros maestros(this->getUser());
                    maestros.run();
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
            
            if (addClassButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                 addClass(); 
            }
            
            if (delClaseButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  eliminarClase();
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
         window.draw(addClassButton);window.draw(addClassTxt);
        window.draw(delClaseButton);window.draw(delClaseTxt);
        window.draw(editClaseButton);window.draw(editClaseTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}

void GestorClases::addClass(){
	Cuentas gestorCuentas("usuarios.txt");
	sf::RenderWindow addWindow(sf::VideoMode(300, 350), "Agregar Clase");
	sf::Font font;
	font.loadFromFile("consola.ttf");
	
	sf::Text titulo("Crear Clase", font, 24); 
	titulo.setPosition(50, 20);
	titulo.setFillColor(sf::Color::Black);

	sf::Text nomTxt("Nombre:", font, 20); 
	nomTxt.setPosition(50, 70);
	nomTxt.setFillColor(sf::Color::Black);
	
	sf::RectangleShape campoNombre ({200, 30});
	campoNombre.setPosition(50, 110);
	campoNombre.setFillColor(sf::Color::White);
	campoNombre.setOutlineColor(sf::Color::Black);
	campoNombre.setOutlineThickness(2);
	
	sf::Text textoInputNombre("", font, 20);
	textoInputNombre.setPosition(50, 110); 
	textoInputNombre.setFillColor(sf::Color::Black);
	
	sf::Text maestroTxt("Maestro:", font, 20); 
	maestroTxt.setPosition(50, 160);
	maestroTxt.setFillColor(sf::Color::Black);
		
	sf::RectangleShape campoMaestro({200, 30});
	campoMaestro.setPosition(50, 200); 
	campoMaestro.setFillColor(sf::Color::White);
	campoMaestro.setOutlineColor(sf::Color::Black);
	campoMaestro.setOutlineThickness(2);
		
	sf::Text textoInputMaestro("", font, 20);
	textoInputMaestro.setPosition(50, 200); 
	textoInputMaestro.setFillColor(sf::Color::Black);
	
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

    while (addWindow.isOpen()) {
        sf::Event event;
        while (addWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                addWindow.close();
            
            if (event.type == sf::Event::MouseButtonPressed) {
                focoUsuario = campoNombre .getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
                focoContrasena = campoMaestro.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
            }
            
            // Captura el texto ingresado
            if (event.type == sf::Event::TextEntered) {
                if (focoUsuario) {
                    if (event.text.unicode == '\b' && !textoInputNombre.getString().isEmpty()) {
                        std::string str = textoInputNombre.getString();
                        str.pop_back();
                        textoInputNombre.setString(str);
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                        textoInputNombre.setString(textoInputNombre.getString() + static_cast<char>(event.text.unicode));
                    }
                } else if (focoContrasena) {
                    if (event.text.unicode == '\b' && !textoInputMaestro.getString().isEmpty()) {
                         std::string str = textoInputMaestro.getString();
                        str.pop_back();
                        textoInputMaestro.setString(str);
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    	textoInputMaestro.setString(textoInputMaestro.getString() + static_cast<char>(event.text.unicode));
                    }
                }
            }
            std::string claseNombre = textoInputNombre.getString();
            std::string usuarioActual = textoInputMaestro.getString();
            std::string type = "MAESTRO";
          	vector <Maestro> usuarios;
			gestorCuentas.leerMaestros(usuarios);
        
		    if (event.type == sf::Event::MouseButtonPressed) {
                if (boton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    if (textoInputNombre.getString().isEmpty() || textoInputMaestro.getString().isEmpty()) {
                        textoError.setString("Por favor, complete ambos campos.");
                    } 
                    for (Maestro _user:usuarios){
                      	if (_user.getUser()==usuarioActual && _user.getTipo()==type){
                      		this->getUser().crearClase(claseNombre, _user);
                        	addWindow.close();
                    	} else {
                    		textoError.setString("Usuario no es valido.");
						}
                }
            }
        }
        
        addWindow.clear(sf::Color::White);
        addWindow.draw(titulo);
        addWindow.draw(maestroTxt);
        addWindow.draw(nomTxt);
        addWindow.draw(campoNombre );
        addWindow.draw(campoMaestro);
        addWindow.draw(textoInputNombre);
        addWindow.draw(textoInputMaestro);
        addWindow.draw(boton);
        addWindow.draw(textoBoton);
        if (!textoError.getString().isEmpty()) {
            addWindow.draw(textoError);
        }
        addWindow.display();
    }
}
}

void GestorClases::eliminarClase(){
	sf::RenderWindow addWindow(sf::VideoMode(300, 350), "Eliminar Clases");
	sf::Font font;
	font.loadFromFile("consola.ttf");
	
	sf::Text titulo("Eliminar Clase", font, 24); 
	titulo.setPosition(50, 20);
	titulo.setFillColor(sf::Color::Black);

	sf::Text userTxt("Clase a eliminar:", font, 20); 
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
            vector <Clase> clases;
			this->getUser().leerClases(clases);
            
            if (event.type == sf::Event::MouseButtonPressed) {
                if (boton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
						
                    if (textoInputUsuario.getString().isEmpty()) {
                        textoError.setString("Por favor, complete el campo.");
                    } 					
					for (Clase clase:clases){
                      	if (clase.getNombre()==usuarioActual){
                      		this->getUser().eliminarClase(textoInputUsuario.getString());
                        	addWindow.close();
                    	} else {
                    		textoError.setString("Clase no existente.");
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

