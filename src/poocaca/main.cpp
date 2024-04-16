#include <SFML/Graphics.hpp>
#include "interface.hpp"


int main() {
    
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML Grid Example");
    interface gameInterface(&window);
    vector<vector<int>> grid = {
        {1, 2, 3},
        {2, 3, 1},
        {3, 1, 2}
    };

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        
        window.clear();
        gameInterface.affichergrid(grid);
        gameInterface.afficherscore();
        window.display();
    }

    return 0;
}
