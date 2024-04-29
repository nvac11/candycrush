#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;

// Auteur : Noé

/*
La classe permet de gérer l’affichage du jeu. 
Elle permet de mettre à jour en temps réel la grille, le score, le nombre de coups restants, ainsi que les moments ou on sélectionne les bonbons en blanc avant de les jouer.
*/
class GridDisplay {
private:
    std::vector<sf::RectangleShape> rectangles;                                                                             // Les formes des bonbons
    std::vector<std::vector<int>> gInner;                                                                                   // grille propre à grid display
    int n;                                                                                                                  // Taille grille
    sf::Font font;
    sf::Text scoreText;
    
public:
    GridDisplay(int n );                                                                                                    // Constructeur avec en paramètre la taille de la grille
    void processRectClicked(sf::Vector2f mousePos, std::pair<std::pair<int, int>, std::pair<int, int>>& clickedPairs);      // Prend en paramètre la position de la souris, et les positions des bonbons sélectionnés pour afficher en blanc les bonbons clickés avant des les jouer ou non.
    void displayGrid(sf::RenderWindow& window) const;                                                                       // Prend en paramètre la fenêtre et affiche la grille.
    void updateRectGrid(vector<vector<int>> g);                                                                             // Prend en paramètre la grille et met à jour la grille d'affichage propre à la classe ainsi que les rectangles.
    void updateScore(int score, int remainingmove);                                                                         // Prend en paramètre le score et le nombre de coups restants et met à jour leur affichage.
    sf::Color intToSFMLColor(int colorCode);                                                                                // Prend le code couleur du bonbon en paramètre et retourne la couleur associée
};