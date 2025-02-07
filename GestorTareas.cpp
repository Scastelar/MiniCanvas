#include "GestorExamenes.h"
#include "GestorTareas.h"
#include "Cuentas.h"

	GestorTareas::GestorTareas(const Maestro& usuario):
		user(usuario){
		}

	Maestro GestorTareas::getUser(){
		return user;
	}

    void GestorTareas::run() {	
	Maestro usuarioActual(this->getUser());
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
    

    
   //Opciones de Tarea
	sf::RectangleShape addTareaButton(sf::Vector2f(170, 40));
    addTareaButton.setPosition(335, 250);
    addTareaButton.setFillColor(sf::Color(171, 97, 169));
    sf::Text addTareaTxt("Agregar Tarea", font, 18);
    addTareaTxt.setPosition(347, 257);
    
    sf::RectangleShape editTareaButton(sf::Vector2f(170, 40));
    editTareaButton.setPosition(335, 300);
    editTareaButton.setFillColor(sf::Color(171, 97, 169));
    sf::Text editTareaTxt("Editar Clase", font, 18);
    editTareaTxt.setPosition(347, 307);
    
    sf::RectangleShape delTareaButton(sf::Vector2f(170, 40));
    delTareaButton.setPosition(335, 350);
    delTareaButton.setFillColor(sf::Color(171, 97, 169));
    sf::Text delTareaTxt("Eliminar Clase", font, 18);
    delTareaTxt.setPosition(347, 357);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)
            window.close();
            

            // Manejo de botones
            if (event.type == sf::Event::MouseButtonPressed) {
             
              if (examButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorExamenes tareas(this->getUser());
                    tareas.run();
                } 
                
			 if (accessButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Maestro acceso(this->getUser());
                    acceso.run();
                } 
            
        }
    }
        

        window.clear();
        window.draw(fondo);
		window.draw(accessButton);
        window.draw(examButton);
        window.draw(tareaButton);
        window.draw(addTareaButton);
        window.draw(addTareaTxt);
        window.draw(editTareaButton);
        window.draw(editTareaTxt);
        window.draw(delTareaButton);
        window.draw(delTareaTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}

