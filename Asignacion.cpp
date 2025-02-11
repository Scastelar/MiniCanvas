#include "GestorAlumnos.h"
#include "GestorMaestros.h"
#include "GestorClases.h"
#include "Asignacion.h"
#include "Cuentas.h"

	Asignacion::Asignacion(const Registro& usuario):
		user(usuario){
		}

	Registro Asignacion::getUser(){
		return user;
	}
	
	

    void Asignacion::run() {	
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
    
 	std::string s = "Asignacion de Clases";
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
    
    sf::RectangleShape asignAlumnoButton(sf::Vector2f(170, 40));
    asignAlumnoButton.setPosition(295, 200);
    asignAlumnoButton.setFillColor(sf::Color(171, 97, 169));
    sf::Text asignAlumnoTxt("Asignar Alumno", font, 18);
    asignAlumnoTxt.setPosition(307, 207);
    
    sf::RectangleShape asignMaestroButton(sf::Vector2f(170, 40));
    asignMaestroButton.setPosition(295, 300);
    asignMaestroButton.setFillColor(sf::Color(171, 97, 169));
    sf::Text asignMaestroTxt("Asignar Maestro", font, 18);
    asignMaestroTxt.setPosition(303, 307);
    

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
            
            if (claseButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  	window.close();
                    GestorClases alumnos(this->getUser());
                    alumnos.run();
            } 
            
            if (asignAlumnoButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  assignAlumno();
            }
            
            if (asignMaestroButton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                  assignMaestro();
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
        window.draw(asignAlumnoButton);window.draw(asignAlumnoTxt);
		window.draw(asignMaestroButton);window.draw(asignMaestroTxt);
        if (!textoError.getString().isEmpty()) {
    	window.draw(textoError);
		}
        window.display();
    }
}

void Asignacion::assignAlumno() {
    Cuentas gestorCuentas("usuarios.txt");
    sf::RenderWindow addWindow(sf::VideoMode(300, 350), "Asignacion");
    sf::Font font;
    font.loadFromFile("consola.ttf");

    sf::Text titulo("Asignar Alumno", font, 24);
    titulo.setPosition(50, 20);
    titulo.setFillColor(sf::Color::Black);

    sf::Text nomTxt("Nombre de Clase:", font, 20);
    nomTxt.setPosition(50, 70);
    nomTxt.setFillColor(sf::Color::Black);

    sf::RectangleShape campoNombre({200, 30});
    campoNombre.setPosition(50, 110);
    campoNombre.setFillColor(sf::Color::White);
    campoNombre.setOutlineColor(sf::Color::Black);
    campoNombre.setOutlineThickness(2);

    sf::Text textoInputNombre("", font, 20);
    textoInputNombre.setPosition(50, 110);
    textoInputNombre.setFillColor(sf::Color::Black);

    sf::Text alumnoTxt("Alumno:", font, 20);
    alumnoTxt.setPosition(50, 160);
    alumnoTxt.setFillColor(sf::Color::Black);

    sf::RectangleShape campoAlumno({200, 30});
    campoAlumno.setPosition(50, 200);
    campoAlumno.setFillColor(sf::Color::White);
    campoAlumno.setOutlineColor(sf::Color::Black);
    campoAlumno.setOutlineThickness(2);

    sf::Text textoInputAlumno("", font, 20);
    textoInputAlumno.setPosition(50, 200);
    textoInputAlumno.setFillColor(sf::Color::Black);

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
    bool focoNombre = false;
    bool focoAlumno = false;

    while (addWindow.isOpen()) {
        sf::Event event;
        while (addWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                addWindow.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                focoNombre = campoNombre.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
                focoAlumno = campoAlumno.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y);
            }

            // Captura el texto ingresado
            if (event.type == sf::Event::TextEntered) {
                if (focoNombre) {
                    if (event.text.unicode == '\b' && !textoInputNombre.getString().isEmpty()) {
                        std::string str = textoInputNombre.getString();
                        str.pop_back();
                        textoInputNombre.setString(str);
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                        textoInputNombre.setString(textoInputNombre.getString() + static_cast<char>(event.text.unicode));
                    }
                } else if (focoAlumno) {
                    if (event.text.unicode == '\b' && !textoInputAlumno.getString().isEmpty()) {
                        std::string str = textoInputAlumno.getString();
                        str.pop_back();
 textoInputAlumno.setString(str);
                    } else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                        textoInputAlumno.setString(textoInputAlumno.getString() + static_cast<char>(event.text.unicode));
                    }
                }
            }

            std::string claseNombre = textoInputNombre.getString();
            std::string usuarioActual = textoInputAlumno.getString();
            std::string type = "ALUMNO";
            vector<Alumno> usuarios;
            vector<Clase> clases;
            gestorCuentas.leerAlumnos(usuarios);

            if (event.type == sf::Event::MouseButtonPressed) {
                if (boton.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
                    if (textoInputNombre.getString().isEmpty() || textoInputAlumno.getString().isEmpty()) {
                        textoError.setString("Por favor, complete ambos campos.");
                    } else {
                        bool alumnoValido = false;
                        for (Alumno _user : usuarios) {
                            if (_user.getUser () == usuarioActual && _user.getTipo() == type) {
                                alumnoValido = true;
                                this->getUser().leerClases(clases);
                                for (Clase& _class : clases) {
                                    if (_class.getNombre() == claseNombre) {
                                        _class.asignarAlumno(_user); // Modificar la clase original
                                        textoError.setString("Alumno asignado con éxito.");
                                        break;
                                    }
                                }
                                if (!alumnoValido) {
                                    textoError.setString("Clase no encontrada.");
                                }
                                break;
                            }
                        }
                        if (!alumnoValido) {
                            textoError.setString("Usuario no es válido.");
                        }
                    }
                }
            }
        }

        addWindow.clear(sf::Color::White);
        addWindow.draw(titulo);
        addWindow.draw(alumnoTxt);
        addWindow.draw(nomTxt);
        addWindow.draw(campoNombre);
        addWindow.draw(campoAlumno);
        addWindow.draw(textoInputNombre);
        addWindow.draw(textoInputAlumno);
        addWindow.draw(boton);
        addWindow.draw(textoBoton);
        if (!textoError.getString().isEmpty()) {
            addWindow.draw(textoError);
        }
        addWindow.display();
    }
}

void Asignacion::assignMaestro(){
	
}
