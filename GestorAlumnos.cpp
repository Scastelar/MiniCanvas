#include "GestorAlumnos.h"
#include "GestorMaestros.h"
#include "GestorClases.h"
#include "Asignacion.h"
#include "Cuentas.h"

	GestorAlumnos::GestorAlumnos(const Registro& usuario):
		user(usuario){
		}

	Registro GestorAlumnos::getUser(){
		return user;
	}

    void GestorAlumnos::run() {	
	Registro usuarioActual(this->getUser());
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
            
            if (claseButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorClases alumnos(this->getUser());
                    alumnos.run();
            } 
                
            if (asignarButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Asignacion asignar(this->getUser());
                    asignar.run();
            }
            
        }
    }
        

        window.clear();
        window.draw(fondo);
        window.draw(accessButton);
        window.draw(maestroButton);
        window.draw(alumnoButton);
        window.draw(claseButton);
        window.draw(asignarButton);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}

