#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

// Author : Conrad

enum class MenuOption {
    Continue,
    PlayNewGame,
    Save,
    Load,
    Quit,
    None
};

class DisplayMenu
{
private:
    sf::Font font;

public:
    DisplayMenu();
    ~DisplayMenu();
    MenuOption displayMenu(sf::RenderWindow& window);
    void displayScoreAndGameOver(sf::RenderWindow& window, int score, bool gameOver);
};
