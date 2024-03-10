#include <SFML/Graphics.hpp>
#include "grid.hpp"
#include "interface.hpp"
#include <iostream>

int main()
{
    grid newgrid = grid();
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");
    newgrid.debugDisplay();

    std::vector<sf::RectangleShape> rectangles;
    for (int i = 0; i < 10; ++i) {
        sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
        rectangle.setPosition(i * 60.f, 100.f);
        rectangle.setFillColor(sf::Color(100 + i * 15, 50 + i * 15, 200 - i * 10));
        rectangles.push_back(rectangle);
    }

    interface i = interface();
    int k = 0;
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        i.affichergrid(&window, &newgrid);
        i.afficherscore(&window, to_string(k++));

        window.display();
    }

    return 0;
}
