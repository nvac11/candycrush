#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include "grid.hpp"
#include "IOevent.hpp"

enum MenuOption { Continue, PlayNewGame, Save, Load, Quit, None };
class interface
{
private:
    sf::Text _text;
    sf::Font _font;
    
public:

    interface();
    ~interface();
    void afficherscore(sf::RenderWindow *window, std::string score) ;
    MenuOption interface::affichermenu(sf::RenderWindow *window, IOevent * ioevent);

    void menu(); // TODO
    void arreter(); // TODO
    void sauvegarder(); // TODO
    void relancer(); // TODO
    void affichergrid(sf::RenderWindow *window, grid *grid);
};