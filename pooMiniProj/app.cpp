#include "app.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>  
#include "EventController.hpp"
#include "GridDisplay.hpp"
#include "grille.hpp"
using namespace std;
app::app(sf::RenderWindow * window, int n)
    : window(window), n(n), gridDisplay(n), eventController(&gridDisplay), menuDisplay()
{}

app::~app()
{}

void app::start(State gs = INGAME){
    gamestate = gs;
    switch (gamestate)
    {
    case INMENU:
        playmenu();
        break;
    case INGAME:
        playgame();
        break;
    case NONE:
        std::cout << "quiting game" << std::endl;
        break;
    default:
        break;
    }
}

void app::playmenu()
{
    DisplayMenu menuDisplay;
    MenuOption choice = menuDisplay.displayMenu(*window);

    switch (choice)
    {
    case MenuOption::Continue:
        std::cout << "Continue selected" << std::endl;
        break;

    case MenuOption::PlayNewGame:
        std::cout << "Play New Game selected" << std::endl;
        start(INGAME);  
        break;

    case MenuOption::Save:
        std::cout << "Save selected" << std::endl;
        break;

    case MenuOption::Load:
        std::cout << "Load selected" << std::endl;
        break;

    case MenuOption::Quit:
        std::cout << "Quit selected" << std::endl;
        window->close();
        break;

    default:
        std::cout << "Unknown option selected" << std::endl;
        break;
    }
}


std::tuple<std::vector<std::vector<int>>, int, int> app::playgame(){
    // initialisation de la grille
    int score = 0;
    int movesremaing = 13;
    bool gamerunning = true;
    vector<vector<int>> g = fillGrid(vector<vector<int>>(n, vector<int>(n, 0))); 
    do {
        g = destructGrid(g, score);
        g = fallGrid(g);
        g = fillGrid(g);
    } while(canBeDestruct(g));
    
    score = 0;
    gridDisplay.updateRectGrid(g);
    gridDisplay.updateScore(score, movesremaing);
    auto lastclicked = std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
    while (window->isOpen() && gamerunning) {
        if(movesremaing <= 0){gamerunning = false;}
        lastclicked = std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
        if(eventController.handleEvent(*window)){
            return std::make_tuple(g, score, movesremaing);
        }
        gridDisplay.displayGrid(*window);
        if (eventController.hasTwoClicked()) {
            auto clickedIndices = eventController.getClickedPairs();
            pair<int, int> c1 = clickedIndices.first;
            pair<int, int> c2 = clickedIndices.second;
            if( lastclicked == clickedIndices){ break;}
            if (isValid(g, c1, c2)) {
                movesremaing--;
                lastclicked = clickedIndices;               
                swap(g[c1.first][c1.second], g[c2.first][c2.second]);
                do {
                    g = destructGrid(g, score);
                    g = fallGrid(g);
                    g = fillGrid(g);
                    gridDisplay.updateScore(score, movesremaing);
                    gridDisplay.updateRectGrid(g);
                } while(canBeDestruct(g) && isSolvable(g));
                if (!isSolvable(g)) {gamerunning = false;}
                eventController.resetClicked();
            }
        }
    }
    return std::make_tuple(g, score, movesremaing);
}