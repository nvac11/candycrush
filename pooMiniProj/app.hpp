#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>  
#include "EventController.hpp"
#include "GridDisplay.hpp"
#include "grid.hpp"
#include "DisplayMenu.hpp"



// Author : Conrad
enum State {INMENU, INGAME, NONE};
struct GameData {
    std::vector<std::vector<int>> g;  
    int score;                         
    int movesremaining;                
};

class app : public Grid
{
    private:
        State gamestate; 
        sf::RenderWindow * window;
        GridDisplay gridDisplay;
        EventController eventController;
        DisplayMenu menuDisplay;
        GameData gameData;
        int n;
    public:
        app(sf::RenderWindow * window , int n );
        ~app();
        void start(State gs);
        void playmenu();
        bool playgame();
        void load(std::string filename);
        void save(std::string filename);
        void flushGameData();
};
