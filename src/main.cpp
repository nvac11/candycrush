#include <SFML/Graphics.hpp>
#include "game.hpp"
#include "interface.hpp"
#include <iostream>

int main(){
    
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");
    /*
    game g = game(&window);
    g.start();    
    */
    grid g = grid();
    g.debugDisplay();

    return 0;
}
