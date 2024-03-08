#pragma once
#include <SFML/Graphics.hpp>

class interface
{
private:
    sf::Text _text;
    sf::Font _font;
    
public:

    interface();
    ~interface();
    void afficherscore(sf::RenderWindow *window);
    void menu(); // TODO
    void arreter(); // TODO
    void sauvegarder(); // TODO
    void relancer(); // TODO
    void affichergrid(); // TODO
};