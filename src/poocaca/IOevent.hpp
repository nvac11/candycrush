#include <SFML/Graphics.hpp>
#pragma once
class IOevent
{
private:
    sf::RenderWindow* _window;
    bool _RightMouseClicked;
    sf::Vector2f _MouseCoord;

public:
    IOevent(sf::RenderWindow* window);

    sf::Vector2f getMousePos();
    void setMousePos(sf::Vector2f coords);

    bool isMouseClickedRight();
    void setMouseClickedRight(bool v);

    void handleEvent(sf::Event event);
};
