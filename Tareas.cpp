#include "Examenes.h"
#include "Tareas.h"
#include "Cuentas.h"

	Tareas::Tareas(const Alumno& usuario):
		user(usuario){
		}

	Alumno Tareas::getUser(){
		return user;
	}

    void Tareas::run() {	
	Alumno usuarioActual(this->getUser());
    Cuentas gestorCuentas("usuarios.txt");
	
    sf::RenderWindow window(sf::VideoMode(800, 500), "Tareas");
    
 

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
	sf::Texture examT;
    if (!examT.loadFromFile("exam.png")) {  
        std::cerr << "Error al cargar la imagen\n";
        return;
    }
    sf::Texture tareaT;
    if (!tareaT.loadFromFile("essay.png")) {  
        std::cerr << "Error al cargar la imagen\n";
        return;
    }
    	sf::Texture accesoT;
    if (!accesoT.loadFromFile("access-control.png")) {  
        std::cerr << "Error al cargar la imagen\n";
        return;
    }


	 // Botones
	sf::Sprite accessButton;
    accessButton.setTexture(accesoT);
    accessButton.setPosition(37, 20); 
    
    sf::Sprite examButton;
    examButton.setTexture(examT);
    examButton.setPosition(32, 120); 
    
    sf::Sprite tareaButton;
    tareaButton.setTexture(tareaT);
    tareaButton.setPosition(32, 200); 
    

    


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)
            window.close();
            

            // Manejo de botones
            if (event.type == sf::Event::MouseButtonPressed) {
             
              if (examButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Examenes tareas(this->getUser());
                    tareas.run();
                } 
                
			 if (accessButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Alumno acceso(this->getUser());
                    acceso.run();
                } 
            
        }
    }
        

        window.clear();
        window.draw(fondo);
		window.draw(accessButton);
        window.draw(examButton);
        window.draw(tareaButton);
      
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}

