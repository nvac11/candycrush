#pragma once
#include <SFML/Graphics.hpp>
#include "GridDisplay.hpp"
#include "EventController.hpp"

class app
{
private:
    sf::RenderWindow * window;
    GridDisplay GridDisplay;
    EventController EventController;

public:
    app();
    ~app();
    void start();
    void playmenu();
    void playgame();
};
