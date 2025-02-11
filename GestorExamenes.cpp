#include "GestorExamenes.h"
#include "GestorTareas.h"
#include "Cuentas.h"

	GestorExamenes::GestorExamenes(const Maestro& usuario):
		user(usuario){
		}

	Maestro GestorExamenes::getUser(){
		return user;
	}
	
	void addExamenFrame();

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
            
              if (addExamen.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
             	addExamenFrame();        
              } 
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

void addExamenFrame() {
    sf::RenderWindow ventana(sf::VideoMode(800, 500), "Examen");
    sf::Font fuente;
    if (!fuente.loadFromFile("consola.ttf")) {
        std::cerr << "Error al cargar la fuente!" << std::endl;
        return;
    }
    
    // Imagen de fondo
    sf::Texture fondoTexture;
    if (!fondoTexture.loadFromFile("fondo3.png")) {
        std::cerr << "Error al cargar la imagen de fondo." << std::endl;
        return;
    }
    sf::Sprite fondo(fondoTexture);

    // Textos
    sf::Text textoClase("Nombre de la Clase:", fuente, 20);
    textoClase.setPosition(50, 50);
    textoClase.setFillColor(sf::Color::Black);

    sf::Text textoPreguntas("Cantidad de Preguntas:", fuente, 20);
    textoPreguntas.setPosition(50, 100);
    textoPreguntas.setFillColor(sf::Color::Black);

    sf::Text textoNombreExamen("Nombre del Examen:", fuente, 20);
    textoNombreExamen.setPosition(50, 150); // Nueva posición para el nombre del examen
    textoNombreExamen.setFillColor(sf::Color::Black);

    sf::Text botonTexto("Crear Examen", fuente, 20);
    botonTexto.setPosition(50, 200);
    botonTexto.setFillColor(sf::Color::White);

    sf::RectangleShape botonCrear(sf::Vector2f(200, 40));
    botonCrear.setPosition(50, 200);
    botonCrear.setFillColor(sf::Color(171, 97, 169));

    sf::Text botonGuardarTexto("Guardar Examen", fuente, 20);
    botonGuardarTexto.setPosition(50, 400);
    botonGuardarTexto.setFillColor(sf::Color::White);

    sf::RectangleShape botonGuardar(sf::Vector2f(200, 40));
    botonGuardar.setPosition(50, 400); 
    botonGuardar.setFillColor(sf::Color(171, 97, 169));

    sf::String nombreClase;
    sf::String cantidadPreguntasStr;
    sf::String nombreExamen; 
    sf::Text textoNombreClase("", fuente, 20);
    textoNombreClase.setPosition(300, 50);
    textoNombreClase.setFillColor(sf::Color::Black);

    sf::Text textoCantidadPreguntas("", fuente, 20);
    textoCantidadPreguntas.setPosition(300, 100);
    textoCantidadPreguntas.setFillColor(sf::Color::Black);

    sf::Text textoNombreExamenInput("", fuente, 20);
    textoNombreExamenInput.setPosition(300, 150); 
    textoNombreExamenInput.setFillColor(sf::Color::Black);

    struct Pregunta {
        sf::String texto;
        std::string tipo;
    };

    std::vector<Pregunta> preguntas;
    std::vector<std::string> tiposDePregunta = {"Verdadero/Falso", "Selección", "Enumerada"};
    std::vector<int> tipoSeleccionado;

    bool escribiendoClase = true;
    bool escribiendoCantidad = false;
    bool escribiendoNombreExamen = false; 
    bool escribiendoPregunta = false;
    bool examenCreado = false;
    int preguntaActual = -1;

    while (ventana.isOpen()) {
        sf::Event evento;
        while (ventana.pollEvent(evento)) {
            if (evento.type == sf::Event::Closed)
                ventana.close();

            if (evento.type == sf::Event::TextEntered) {
                if (escribiendoClase) {
                    if (evento.text.unicode == 13) {
                        escribiendoClase = false;
                        escribiendoCantidad = true;
                    } else if (evento.text.unicode == 8 && !nombreClase.isEmpty()) {
                        nombreClase.erase(nombreClase.getSize() - 1);
                    } else if (evento.text.unicode < 128) {
                        nombreClase += evento.text.unicode;
                    }
                } else if (escribiendoCantidad) {
                    if (evento.text.unicode == 13) {
                        escribiendoCantidad = false;
                        escribiendoNombreExamen = true;
                    } else if (evento.text.unicode == 8 && !cantidadPreguntasStr.isEmpty()) {
                        cantidadPreguntasStr.erase(cantidadPreguntasStr.getSize() - 1);
                    } else if (evento.text.unicode >= '0' && evento.text.unicode <= '9') {
                        cantidadPreguntasStr += evento.text.unicode;
                    }
                } else if (escribiendoNombreExamen) { 
                    if (evento.text.unicode == 13) {
                        escribiendoNombreExamen = false; 
                        escribiendoPregunta = true;
                    } else if (evento.text.unicode == 8 && !nombreExamen.isEmpty()) {
                        nombreExamen.erase(nombreExamen.getSize() - 1);
                    } else if (evento.text.unicode < 128) {
                        nombreExamen += evento.text.unicode;
                    }
                } else if (escribiendoPregunta && preguntaActual >= 0) {
                    if (evento.text.unicode == 8 && !preguntas[preguntaActual].texto.isEmpty()) {
                        preguntas[preguntaActual].texto.erase(preguntas[preguntaActual].texto.getSize() - 1);
                    } else if (evento.text.unicode < 128 && evento.text.unicode != 13) {
                        preguntas[preguntaActual].texto += evento.text.unicode;
                    } else if (evento.text.unicode == 13) {
                        escribiendoPregunta = false; 
                    }
                }
            }

            if (evento.type == sf::Event::MouseButtonPressed) {
                if (evento.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f posMouse(evento.mouseButton.x, evento.mouseButton.y);

                    if (botonCrear.getGlobalBounds().contains(posMouse)) {
                        int numPreguntas = std::stoi(cantidadPreguntasStr.toAnsiString());
                        preguntas.resize(numPreguntas, {"", "Verdadero/Falso"});
                        tipoSeleccionado.resize(numPreguntas, 0);
                        examenCreado = true;
                    }

                    if (botonGuardar.getGlobalBounds().contains(posMouse) && examenCreado) {
                        std::ofstream archivo(nombreExamen.toAnsiString() + "_examen.txt"); 
                        archivo << "Clase: " << nombreClase.toAnsiString() << "\n";
                        for (size_t i = 0; i < preguntas.size(); i++) {
                            archivo << "Pregunta " << i + 1 << ": " << preguntas[i].texto.toAnsiString()
                                    << " [" << preguntas[i].tipo << "]\n";
                        }
                        archivo.close();
                        ventana.close();
                    }

                    if (examenCreado) {
                        for (size_t i = 0; i < preguntas.size(); i++) {
                            sf::FloatRect areaPregunta(50, 250 + (i * 50), 400, 30);
                            if (areaPregunta.contains(posMouse)) {
                                escribiendoPregunta = true;
                                preguntaActual = i;
                                break; 
                            }

                            sf::FloatRect areaTipo(470, 250 + (i * 50), 200, 30);
                            if (areaTipo.contains(posMouse)) {
                                tipoSeleccionado[i] = (tipoSeleccionado[i] + 1) % tiposDePregunta.size();
                                preguntas[i].tipo = tiposDePregunta[tipoSeleccionado[i]];
                            }
                        }
                    } else {
                        escribiendoPregunta = false;
                    }

                    if (textoNombreExamenInput.getGlobalBounds().contains(posMouse)) {
                        escribiendoNombreExamen = true;
                    }
                }
            }
        }

        textoNombreClase.setString(nombreClase);
        textoCantidadPreguntas.setString(cantidadPreguntasStr);
        textoNombreExamenInput.setString(nombreExamen); 

        ventana.clear();
        ventana.draw(fondo);
        ventana.draw(textoClase);
        ventana.draw(textoPreguntas);
        ventana.draw(textoNombreExamen);
        ventana.draw(textoNombreClase);
        ventana.draw(textoCantidadPreguntas);
        ventana.draw(textoNombreExamenInput); 

        ventana.draw(botonCrear);
        ventana.draw(botonTexto);

        if (examenCreado) {
            for (size_t i = 0; i < preguntas.size(); i++) {
                sf::Text textoPregunta(preguntas[i].texto, fuente, 18);
                textoPregunta.setPosition(50, 250 + (i * 50));
                textoPregunta.setFillColor(sf::Color::Black);
                ventana.draw(textoPregunta);

                sf::Text textoTipo(tiposDePregunta[tipoSeleccionado[i]], fuente, 18);
                textoTipo.setPosition(470, 250 + (i * 50));
                textoTipo.setFillColor(sf::Color(171, 97, 169));
                ventana.draw(textoTipo);
            }

            ventana.draw(botonGuardar);
            ventana.draw(botonGuardarTexto);
        }

        ventana.display();
    }
}


