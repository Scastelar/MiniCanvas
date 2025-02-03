#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

class ComboBox {
private:
    sf::RectangleShape box;
    sf::Text selectedText;
    std::vector<sf::Text> options;
    sf::Font font;
    bool isOpen = false;

public:
    ComboBox(float x, float y, const std::vector<std::string>& items);

    void handleEvent(sf::Event event, sf::RenderWindow& window);
    void draw(sf::RenderWindow& window);
    std::string getSelectedOption() const;
};

#endif


