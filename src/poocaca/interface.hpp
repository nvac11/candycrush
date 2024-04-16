#pragma once
#include <vector>
#include <SFML/Graphics.hpp>
#include "IOevent.hpp"
#include "CursorSelection.hpp"
using namespace std;

class interface {
private:
    sf::RenderWindow* window; 
    IOevent * ioevent;
    CursorSelection * c;
    std::vector<sf::RectangleShape> rectangles;
public:
    sf::Font font; 

    interface(sf::RenderWindow * win, IOevent * ioevent, CursorSelection * c); 
    void affichergrid(vector<vector<int>> g);
    void afficherscore();
    void affichermenu(); 
};

sf::Color getColorForValue(int value);