#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

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

    sf::Color intToSFMLColor(int colorCode);

public:
    DisplayMenu();
    ~DisplayMenu();

    MenuOption displayMenu(sf::RenderWindow& window);
    void displayScoreAndGameOver(sf::RenderWindow& window, int score, bool gameOver);
};
