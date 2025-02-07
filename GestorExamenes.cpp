#include "GestorExamenes.h"
#include "GestorTareas.h"
#include "Cuentas.h"

	GestorExamenes::GestorExamenes(const Maestro& usuario):
		user(usuario){
		}

	Maestro GestorExamenes::getUser(){
		return user;
	}

    void GestorExamenes::run() {	
	Maestro usuarioActual(this->getUser());
    Cuentas gestorCuentas("usuarios.txt");
	
    sf::RenderWindow window(sf::VideoMode(800, 500), "Examenes");
    
 

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
    

    
    //Opciones de Examen
    sf::RectangleShape addExamen(sf::Vector2f(170, 40));
    addExamen.setPosition(140, 250);
    addExamen.setFillColor(sf::Color(171, 97, 169));
    sf::Text addExamenTxt("Crear Examen", font, 18);
    addExamenTxt.setPosition(152, 257);

	 sf::RectangleShape editExamen(sf::Vector2f(170, 40));
    editExamen.setPosition(140, 300);
    editExamen.setFillColor(sf::Color(171, 97, 169));
    sf::Text editExamenTxt("Editar Examen", font, 18);
    editExamenTxt.setPosition(152, 307);
    
    sf::RectangleShape delExamen(sf::Vector2f(170, 40));
    delExamen.setPosition(140, 350);
    delExamen.setFillColor(sf::Color(171, 97, 169));
    sf::Text delExamenTxt("Eliminar Examen", font, 18);
    delExamenTxt.setPosition(152, 357);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)
            window.close();
            

            // Manejo de botones
            if (event.type == sf::Event::MouseButtonPressed) {
             
              if (tareaButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorTareas tareas(this->getUser());
                    tareas.run();
                } 
                
			 if (accessButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Maestro acceso(this->getUser());
                    acceso.run();
                } 
            
             // if (addExamen.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  
                   
             //   } 
        }
    }
        

        window.clear();
        window.draw(fondo);
        window.draw(accessButton);
        window.draw(examButton);
        window.draw(tareaButton);
         window.draw(addExamen);
        window.draw(addExamenTxt);
        window.draw(editExamen);
        window.draw(editExamenTxt);
        window.draw(delExamen);
        window.draw(delExamenTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}

