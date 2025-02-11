#include "Cuentas.h"
#include "ComboBox.h"
#include "Login.h"
#include "Alumno.h"
#include "Examenes.h"
#include "Tareas.h"

	Alumno::Alumno(const string& tipo,const string& user,const string& pass)
	
		: Usuario("ALUMNO",user,pass), carrera(" "){
		}
		
	
		
		string Alumno::getCarrera(){
			return carrera;
		}
	
	void Alumno::run() {
	
	Alumno usuarioActual(this->getTipo(),this->getUser(),this->getPassword());
    Cuentas gestorCuentas("usuarios.txt");
	
    sf::RenderWindow window(sf::VideoMode(800, 500), "Alumno");
    
 

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
    sf::Text tituloTxt(titulo, font, 20);
	tituloTxt.setPosition(295, 70);
	tituloTxt.setFillColor(sf::Color::Black);
 
	
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
    
   

    //Cerrar Sesion
    sf::RectangleShape logoutButton(sf::Vector2f(170, 40));
    logoutButton.setPosition(550, 350);
    logoutButton.setFillColor(sf::Color::Red);
    sf::Text logoutTxt("Cerrar Sesion", font, 18);
    logoutTxt.setPosition(562, 357);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)
            window.close();
            

            // Manejo de botones
            if (event.type == sf::Event::MouseButtonPressed) {
             
          if (examButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Examenes examen(usuarioActual);
                    examen.run();
                } 
                
                if (tareaButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    Tareas tarea(usuarioActual);
                    tarea.run();
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
         window.draw(examButton);
        window.draw(tareaButton);
        window.draw(accessButton);
        window.draw(logoutButton);
        window.draw(logoutTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}
