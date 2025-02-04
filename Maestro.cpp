#include "Cuentas.h"
#include "ComboBox.h"
#include "Login.h"
#include "Maestro.h"

	Maestro::Maestro(const string& tipo,const string& user,const string& pass)
		: Usuario("MAESTRO",user,pass), salario(0){
	}
	
	double Maestro::getSalario() const{
		return salario;
	}
	
	void Maestro::run() {
	
//	Registro usuarioActual(tipo,user,pass,salario);
    Cuentas gestorCuentas("usuarios.txt");
	
    sf::RenderWindow window(sf::VideoMode(800, 500), "Maestro");
    
 

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
	
    

    // Botones
    //Opciones de Examen
    sf::RectangleShape addExamen(sf::Vector2f(170, 40));
    addExamen.setPosition(140, 250);
    addExamen.setFillColor(sf::Color::Cyan);
    sf::Text addExamenTxt("Crear Examen", font, 18);
    addExamenTxt.setPosition(152, 257);

	 sf::RectangleShape editExamen(sf::Vector2f(170, 40));
    editExamen.setPosition(140, 300);
    editExamen.setFillColor(sf::Color::Cyan);
    sf::Text editExamenTxt("Editar Examen", font, 18);
    editExamenTxt.setPosition(152, 307);
    
    sf::RectangleShape delExamen(sf::Vector2f(170, 40));
    delExamen.setPosition(140, 350);
    delExamen.setFillColor(sf::Color::Cyan);
    sf::Text delExamenTxt("Eliminar Examen", font, 18);
    delExamenTxt.setPosition(152, 357);
    
    //Opciones de Tarea
	sf::RectangleShape addTareaButton(sf::Vector2f(170, 40));
    addTareaButton.setPosition(335, 250);
    addTareaButton.setFillColor(sf::Color::Magenta);
    sf::Text addTareaTxt("Agregar Tarea", font, 18);
    addTareaTxt.setPosition(347, 257);
    
    sf::RectangleShape editTareaButton(sf::Vector2f(170, 40));
    editTareaButton.setPosition(335, 300);
    editTareaButton.setFillColor(sf::Color::Magenta);
    sf::Text editTareaTxt("Editar Clase", font, 18);
    editTareaTxt.setPosition(347, 307);
    
    sf::RectangleShape delTareaButton(sf::Vector2f(170, 40));
    delTareaButton.setPosition(335, 350);
    delTareaButton.setFillColor(sf::Color::Magenta);
    sf::Text delTareaTxt("Eliminar Clase", font, 18);
    delTareaTxt.setPosition(347, 357);

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
             
           // if (addExamen.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  
                   
             //   } 
             
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
        window.draw(addExamen);
        window.draw(addExamenTxt);
        window.draw(editExamen);
        window.draw(editExamenTxt);
        window.draw(delExamen);
        window.draw(delExamenTxt);
        window.draw(addTareaButton);
        window.draw(addTareaTxt);
        window.draw(editTareaButton);
        window.draw(editTareaTxt);
        window.draw(delTareaButton);
        window.draw(delTareaTxt);
        window.draw(logoutButton);
        window.draw(logoutTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}
