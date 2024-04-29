#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

// Auteur : Conrad

/*
Cette classe gère tout ce qui est en rapport avec le menu que ce soit l’affichage ou les évènements à l’interieur de la fenêtre menu. 
Elle se sert aussi d’une enumération d’état pour gérer les différentes options du menu.
Enfin elle affiche la fenêtre de fin et le score final.
*/

enum class MenuOption {                                                                 // Enumère les différentes options du menu
    Continue,
    PlayNewGame,
    Save,
    Load,
    Quit,
    None
};

class DisplayMenu {
private:
    sf::Font font;                                                                      // Police d'écriture

public:
    DisplayMenu();                                                                      // Constructeur
    ~DisplayMenu();                                                                     // Destructeur
    MenuOption displayMenu(sf::RenderWindow& window);                                   // Prend en paramètre la fenêtre et affiche la fenêtre du menu et gère les évènements dans le menu.
    void displayScoreAndGameOver(sf::RenderWindow& window, int score, bool gameOver);   // Prend en paramètre la fenêtre, le score et si la partie est finie ou non et gère l'affichage du score final et la fenêtre game over.
};