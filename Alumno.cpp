#include "Cuentas.h"
#include "ComboBox.h"
#include "Login.h"
#include "Alumno.h"

	Alumno::Alumno(const string& tipo,const string& user,const string& pass)
	
		: Usuario("ALUMNO",user,pass), carrera(" "){
		}
		
	
		
		string Alumno::getCarrera(){
			return carrera;
		}
	
	void Alumno::run() {
	
//	Registro usuarioActual(tipo,user,pass,salario);
    Cuentas gestorCuentas("usuarios.txt");
	
    sf::RenderWindow window(sf::VideoMode(800, 500), "Login");
    
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
	tituloTxt.setPosition(295, 150);
	tituloTxt.setFillColor(sf::Color::Black);
 
	
    sf::Text textoError("", font, 20);
	textoError.setPosition(240, 380);
	textoError.setFillColor(sf::Color::Red);
	

    //Cerrar Sesion
    sf::RectangleShape logoutButton(sf::Vector2f(170, 40));
    logoutButton.setPosition(530, 350);
    logoutButton.setFillColor(sf::Color::Red);
    sf::Text logoutTxt("Cerrar Sesion", font, 18);
    logoutTxt.setPosition(542, 357);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        	if (event.type == sf::Event::Closed)
            window.close();
            

            // Manejo de botones
            if (event.type == sf::Event::MouseButtonPressed) {
           
             
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
        window.draw(logoutButton);
        window.draw(logoutTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}
