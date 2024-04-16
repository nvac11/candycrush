#include <SFML/Graphics.hpp>
#include "interface.hpp"
#include <string>

using namespace std;

sf::Color getColorForValue(int value) {
    switch (value) {
        case 1:
            return sf::Color::Red;
        case 2:
            return sf::Color::Blue;
        case 3:
            return sf::Color::Green;
        default:
            return sf::Color::White;
    }
}
interface::interface(sf::RenderWindow* win, IOevent * ioevent, CursorSelection * c) : window(win), ioevent(ioevent), c(c){ // Initialize window
    if (!font.loadFromFile("../arial.ttf")) {
        // Handle font loading error
    }
}

void interface::affichergrid(std::vector<std::vector<int>> g) {
    rectangles.clear(); 

    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
            rectangle.setPosition(j * 60.f, i * 60.f);
            rectangle.setFillColor(getColorForValue(g[i][j]));  
            rectangles.push_back(rectangle);
        }
    }
    
    for (auto& rectangle : rectangles) {
        window->draw(rectangle);
    }

    if (ioevent->isMouseClickedRight()) {
        for (auto& rectangle : rectangles) {
            if (rectangle.getGlobalBounds().contains(ioevent->getMousePos())) {
                rectangle.setFillColor(sf::Color::White);
            }
        }
    }
}



void interface::afficherscore() {
    sf::Text displayText;
    sf::Vector2f mousePos = ioevent->getMousePos();  // Assuming ioevent is defined somewhere
    std::string posString = std::to_string((int)mousePos.x) + ", " + std::to_string((int)mousePos.y);
    
    displayText.setFont(font);
    displayText.setString(posString);
    displayText.setFillColor(sf::Color::White);
    displayText.setPosition(600, 100);
    
    window->draw(displayText);
}

void interface::affichermenu() {
    // Your menu display code here
}
