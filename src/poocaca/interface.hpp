#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

using namespace std;

class interface {
private:
    sf::RenderWindow* window; 

public:
    sf::Font font; 

    interface(sf::RenderWindow* win); 
    void affichergrid(vector<vector<int>> g);
    void afficherscore();
    void affichermenu(); 
};

sf::Color getColorForValue(int value);