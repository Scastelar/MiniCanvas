#include "ComboBox.h"


    ComboBox::ComboBox(float x, float y, const std::vector<std::string>& items) {
        font.loadFromFile("consola.ttf");  // Asegúrate de tener una fuente

        // Configurar el cuadro principal
        box.setSize({200, 30});
        box.setPosition(x, y);
        box.setFillColor(sf::Color::White);
        box.setOutlineColor(sf::Color::Black);
        box.setOutlineThickness(2);

        // Configurar el texto seleccionado
        selectedText.setFont(font);
        selectedText.setCharacterSize(18);
        selectedText.setFillColor(sf::Color::Black);
        selectedText.setPosition(x + 10, y + 5);
        selectedText.setString(items[0]);  // Primer elemento por defecto

        // Configurar las opciones
        for (size_t i = 0; i < items.size(); i++) {
            sf::Text option;
            option.setFont(font);
            option.setCharacterSize(18);
            option.setFillColor(sf::Color::Black);
            option.setString(items[i]);
            option.setPosition(x + 10, y + 40 + (i * 30));
            options.push_back(option);
        }
    }

    void ComboBox::handleEvent(sf::Event event, sf::RenderWindow& window) {
        if (event.type == sf::Event::MouseButtonPressed) {
            sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
            if (box.getGlobalBounds().contains(mousePos)) {
                isOpen = !isOpen;  // Alternar abrir/cerrar
            } else if (isOpen) {
                // Verificar si se selecciona una opción
                for (size_t i = 0; i < options.size(); i++) {
                    if (options[i].getGlobalBounds().contains(mousePos)) {
                        selectedText.setString(options[i].getString());
                        isOpen = false;
                        break;
                    }
                }
            }
        }
    }

    void ComboBox::draw(sf::RenderWindow& window) {
        window.draw(box);
        window.draw(selectedText);
        if (isOpen) {
            for (const auto& option : options) {
                window.draw(option);
            }
        }
    }
    
    std::string ComboBox::getSelectedOption() const {
    return selectedText.getString();
	}





