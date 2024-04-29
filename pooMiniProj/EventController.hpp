#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <utility>
#include "GridDisplay.hpp"


// Auteur : Conrad

/*
Cette classe gère les évènements créés par l’utilisateur comme les clics souris et les touches claviers notamment la touche échap pour le menu et la sélection des bonbons au clic gauche. 
Cette classe ne gère que les évènements dans la fenêtre jeu.
*/

class EventController {
    private:
    GridDisplay * gdisplay;                                                     // Pointeur de la classe GridDisplay
    std::pair<std::pair<int, int>, std::pair<int, int>> clickedPairs;           // C'est une paire de deux paires qui sont les positions des deux bonbons sélectionnés sur la grille.

    public:
    EventController(GridDisplay *g);                                            // Constructeur en prenant en entrée l'adresse de la grille affichée actuelle.
    bool handleEvent(sf::RenderWindow& window);                                 // Elle prend en entrée la fenêtre et retourne true si on veut aller vers le menu false sinon, et gère les clics souris et la touche echap.
    std::pair<std::pair<int, int>, std::pair<int, int>>& getClickedPairs();     // Retourne les positions sélectionnées.
    bool hasTwoClicked() const;                                                 // Retourne un booléen si deux bonbons ont été sélectionnés.
    void resetClicked();                                                        // Remet les positions cliquées par défaut à (-1,-1)
    bool noRectClicked() const;                                                 // Sert à savoir si aucun n'a été sélectionné.
};