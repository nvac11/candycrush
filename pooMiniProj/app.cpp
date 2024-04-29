#include "app.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>  
#include "EventController.hpp"
#include "GridDisplay.hpp"
#include <fstream>
#include "grid.hpp"

using namespace std;

app::app(sf::RenderWindow * window, int n)
    : window(window), n(n), gridDisplay(n), eventController(&gridDisplay), menuDisplay()
{
    flushGameData();
}

app::~app(){}

void app::start(State gs = INMENU){
    gamestate = gs;
    while(gamestate != NONE){
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
}

void app::playmenu()
{
    DisplayMenu menuDisplay;
    MenuOption choice = menuDisplay.displayMenu(*window);

    switch (choice)
    {
    case MenuOption::Continue:
        std::cout << "Continue selected" << std::endl; 
        if(!playgame()){
            menuDisplay.displayScoreAndGameOver(*window, gameData.score, true);
        }
        break;
    case MenuOption::PlayNewGame:
        std::cout << "Play New Game selected" << std::endl;
        flushGameData();
        if(!playgame()){
            menuDisplay.displayScoreAndGameOver(*window, gameData.score, true);
        }
        
        break;
    case MenuOption::Save:
        std::cout << "Save selected" << std::endl;
        save("file1.txt");
        break;

    case MenuOption::Load:
        std::cout << "Load selected" << std::endl;
        load("file1.txt");
        break;

    case MenuOption::Quit:
        std::cout << "Quit selected" << std::endl;
        gamestate = NONE;
        window->close();
        break;
    default:
        std::cout << "Unknown option selected" << std::endl;
        window->close();
        break;
    }
}
void app::load(std::string filename) {
    std::ifstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }

    file >> gameData.score;
    file >> gameData.movesremaining;
    gameData.g.resize(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file >> gameData.g[i][j];
        }
    }

    file.close();
}

void app::save(std::string filename) {
    std::ofstream file(filename);
    
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return;
    }
    file << gameData.score << std::endl;
    file << gameData.movesremaining << std::endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            file << gameData.g[i][j] << " ";
        }
        file << std::endl;
    }
    file.close();
}

bool app::playgame(){
    vector<vector<int>> g = gameData.g;
    
    int score;
    bool gamerunning = true;
    do {
        g = destructGrid(g, score);
        g = fallGrid(g);
        g = fillGrid(g);
    } while(canBeDestruct(g));
    gridDisplay.updateRectGrid(g);
    gridDisplay.updateScore(gameData.score, gameData.movesremaining);
    auto lastclicked = std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
    while (window->isOpen() && gamerunning) {
        if(gameData.movesremaining <= 0){gamerunning = false;}
        lastclicked = std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
        if(eventController.handleEvent(*window)){
            gameData.g = g;
            return true;
        }
        gridDisplay.displayGrid(*window);
        if (eventController.hasTwoClicked()) {
            auto clickedIndices = eventController.getClickedPairs();
            auto c1 = clickedIndices.first;
            auto c2 = clickedIndices.second;
            if(lastclicked == clickedIndices){ break;}
            if (isValid(g, c1, c2)) {
                gameData.movesremaining--;
                lastclicked = clickedIndices;               
                swap(g[c1.first][c1.second], g[c2.first][c2.second]);
                do {
                    g = destructGrid(g, gameData.score);
                    g = fallGrid(g);
                    g = fillGrid(g);
                    gridDisplay.updateScore(gameData.score, gameData.movesremaining);
                    gridDisplay.updateRectGrid(g);
                } while(canBeDestruct(g) && isSolvable(g));
                if (!isSolvable(g)) {gamerunning = false;}
                eventController.resetClicked();
            }
        }
    }
    gameData.g = g;
    return false;
}

void app::flushGameData() {
    gameData.g = fillGrid(std::vector<std::vector<int>>(n, std::vector<int>(n, 0)));
    gameData.score = 0;
    gameData.movesremaining = 30;
}