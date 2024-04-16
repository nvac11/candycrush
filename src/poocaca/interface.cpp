#include <SFML/Graphics.hpp>
#include "interface.hpp"


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
interface::interface(sf::RenderWindow* win) : window(win) { // Initialize window
    if (!font.loadFromFile("../arial.ttf")) {
        // Handle font loading error
    }
}

void interface::affichergrid(vector<vector<int>> g) {
    std::vector<sf::RectangleShape> rectangles;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
            rectangle.setPosition(j * 60.f, i * 60.f);
            rectangle.setFillColor(getColorForValue(g[i][j]));  
            rectangles.push_back(rectangle);
        }
    }
    for (const auto& rectangle : rectangles) {
        window->draw(rectangle);
    }        
}

void interface::afficherscore() {
    sf::Text displayText;
    displayText.setFont(font);
    displayText.setString("coucou");
    displayText.setFillColor(sf::Color::White);
    displayText.setPosition(600, 100);
    window->draw(displayText);
}

void interface::affichermenu() {
    // Your menu display code here
}


//void affichermenu(sf::RenderWindow &window);