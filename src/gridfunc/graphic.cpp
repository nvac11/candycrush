#include "graphic.hpp"
#include <vector>

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

void affichergrid(sf::RenderWindow *window, vector<vector<int>> g) {
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
