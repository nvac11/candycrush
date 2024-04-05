#include "interface.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

interface::interface() {
    if (!_font.loadFromFile("arial.ttf")) {
        std::cout << "Can't load arial.ttf" << std::endl;
    } else {
        std::cout << "Loaded arial.ttf successfully" << std::endl;
    }

    _text.setFont(_font);
    _text.setCharacterSize(24);
    _text.setFillColor(sf::Color::Red);
    _text.setPosition(700.f, 100.f);
}

interface::~interface() {}

void interface::afficherscore(sf::RenderWindow *window, std::string score) {
    window->draw(_text);
    _text.setString(score);
}

sf::Color enumToColor(colors color)
    {
        switch(color) {
            case RED:
                return sf::Color::Red;
                
            case BLUE:
                return sf::Color(0xd7f0f4);
                
            case GREEN:
                return sf::Color::Green;
                
            case PURPLE:
                return sf::Color(128, 0, 128);
                
            default:
                return sf::Color::White; // Default color or handle the default case appropriately

        }
    }

void interface::affichergrid(sf::RenderWindow *window, grid *grid) {
    std::vector<sf::RectangleShape> rectangles;
    
    // Function to convert enum value to corresponding SFML color
        
    
    for (int i = 0; i < grid->_grid.size(); i++) {
        for (int j = 0; j < grid->_grid[i].size(); j++) { // Fix: use grid->_grid[i].size() for the inner loop
            sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
            rectangle.setPosition(i * 60.f, j * 60.f);
            rectangle.setFillColor(enumToColor(grid->_grid[i][j]->getColor())); // Fill color based on enum value
            rectangles.push_back(rectangle);   
        }
    }
    for (const auto& rectangle : rectangles) {
        window->draw(rectangle);
    }    
}


MenuOption interface::affichermenu(sf::RenderWindow *window, IOevent *ioevent) {
    sf::Color textColorW = sf::Color::White;
    sf::Color textColorR = sf::Color::Red;

    unsigned int textSize = 30;

    float x = 100.f;
    float y = 100.f;
    float spacing = 30.f;

    float rectWidth = 300.f;
    float rectHeight = 5 * textSize + 5 * spacing;

    sf::RectangleShape rect(sf::Vector2f(rectWidth, rectHeight));
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(2);

    rect.setPosition(x - 10.f, y - 10.f);

    window->draw(rect);

    for (int i = 0; i < 5; ++i) {
        sf::Text button;
        button.setFont(_font);
        MenuOption currentOption;
        switch (static_cast<MenuOption>(i)) {
            case MenuOption::Continue:
                button.setString("Continue");
                currentOption = MenuOption::Continue;
                break;
            case MenuOption::PlayNewGame:
                button.setString("Play New Game");
                currentOption = MenuOption::PlayNewGame;
                break;
            case MenuOption::Save:
                button.setString("Save");
                currentOption = MenuOption::Save;
                break;
            case MenuOption::Load:
                button.setString("Load");
                currentOption = MenuOption::Load;
                break;
            case MenuOption::Quit:
                button.setString("Quit");
                currentOption = MenuOption::Quit;
                break;
            default:
                button.setString("Unknown Option");
                currentOption = MenuOption::Unknown;
                break;
        }

        button.setCharacterSize(textSize);
        if (isInsideBox(ioevent->getMousePos(), sf::Vector2f(x + 10, y), 300, 20)) {
            button.setFillColor(textColorR);
            if (ioevent->isMouseClicked()) {
                return currentOption; // Return the selected menu option
            }
        } else {
            button.setFillColor(textColorW);
        }
        button.setPosition(x, y);
        window->draw(button);
        y += textSize + spacing;
    }

    // If no option is clicked, return a default value
    return MenuOption::Unknown;
}
