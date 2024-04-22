#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>  
#include "EventController.hpp"
#include "GridDisplay.hpp"
#include "grille.hpp"
#include "DisplayMenu.hpp"
enum State {INMENU, INGAME, NONE};

class app
{

    private:
        State gamestate; 
        sf::RenderWindow * window;
        GridDisplay gridDisplay;
        EventController eventController;
        DisplayMenu menuDisplay;
        int n;
    public:
        app(sf::RenderWindow * window , int n );
        ~app();
        void start(State gs);
        void playmenu();
        std::tuple<std::vector<std::vector<int>>, int, int> playgame();
        std::tuple<std::vector<std::vector<int>>, int, int> load(std::string filename);
        void save(std::string filename, std::vector<std::vector<int>> g, int score, int remainingmoves);
};
