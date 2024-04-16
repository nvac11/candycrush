#include <SFML/Graphics.hpp>
#include "IOevent.hpp"
#include <iostream>

IOevent::IOevent(sf::RenderWindow* window)
    : _window(window), _RightMouseClicked(false)
{
}

sf::Vector2f IOevent::getMousePos()
{
    return _MouseCoord;
}

void IOevent::setMousePos(sf::Vector2f coords)
{
    _MouseCoord = coords;
}

bool IOevent::isMouseClickedRight()
{
    bool value = _RightMouseClicked;
    _RightMouseClicked = false;  
    return value;
}

void IOevent::setMouseClickedRight(bool v)
{
    _RightMouseClicked = v;
}

void IOevent::handleEvent(sf::Event event)
{
    if (event.type == sf::Event::MouseButtonPressed)
    {
        std::cout << "mousse clicked";
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            _RightMouseClicked = true;
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased)
    {
        if (event.mouseButton.button == sf::Mouse::Right)
        {
            _RightMouseClicked = false;
        }
    }
    else if (event.type == sf::Event::MouseMoved)
    {
        _MouseCoord = sf::Vector2f(event.mouseMove.x, event.mouseMove.y);
    }
}
