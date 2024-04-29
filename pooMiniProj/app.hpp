#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>  
#include "EventController.hpp"
#include "GridDisplay.hpp"
#include "grid.hpp"
#include "DisplayMenu.hpp"

// Auteur : Conrad

/* 
Cette classe sert à gérer le déroulement de la partie. Elle contient la grille actuelle, le score et le nombre de coups restants dans une struct GameData dans un de ses champs. 
Elle contient aussi une variable gamestate qui indique si on est en jeu ou dans le menu, les variables d'affichage et la fenêtre SFML dans laquelle on est. 
C’est cette classe qui permet de sauvegarder, créer ou charger une partie ainsi que l’initialisation et les différents tours du jeu.
*/

enum State {INMENU, INGAME, NONE};                      // Explicite si on se trouve dans le menu ou dans la fenêtre de jeu.

struct GameData {
    std::vector<std::vector<int>> g;                    // grille actuelle
    int score;                        
    int movesremaining;            
};

class app : public Grid {
    private:
        State gamestate;
        sf::RenderWindow * window;
        GridDisplay gridDisplay;
        EventController eventController;
        DisplayMenu menuDisplay;
        GameData gameData;
        int n;                                          // Taille de la grille
    public:
        app(sf::RenderWindow * window , int n );        // Constructeur qui prend en paramètre la fenêtre SFML et la taille de la grille qui sera n*n
        ~app();                                         // Destructeur
        void start(State gs);                           // Pour demarrer la partie en fonction de l'état depuis le menu ou le jeu.
        void playmenu();                                // Gère le menu et l'affiche.
        bool playgame();                                // Gère le jeu et l'affiche.
        void load(std::string filename);                // Charger la partie sauvegardée si elle existe à partir du fichier texte filename.
        void save(std::string filename);                // Sauvergarder la partie dans le fichier texte filename. On ne peut sauvergarder qu'une seule partie à la fois.
        void flushGameData();                           // Initialisation d'une grille de départ.
};