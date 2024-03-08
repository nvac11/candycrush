#include "interface.hpp"
#include <iostream>

interface::interface() {
    if (!_font.loadFromFile("arial.ttf")) {
        std::cout << "Can't load arial.ttf" << std::endl;
    } else {
        std::cout << "Loaded arial.ttf successfully" << std::endl;
    }

    _text.setFont(_font);
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::Red);
    _text.setPosition(400.f, 200.f);
}

interface::~interface() {}

void interface::afficherscore(sf::RenderWindow *window) {
    window->draw(_text);
    _text.setString("Hello, SFML!");
}