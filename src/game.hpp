#pragma once
#include "grid.hpp"
#include "interface.hpp"
#include "IOevent.hpp"
#include "data.hpp" // Include data.hpp

enum State {INMENU, INGAME, NONE};

class game {
private:
    Data gameData; // Use Data as a member
    grid* _grid;
    interface* _interface;
    IOevent* _IOevent; 
    sf::RenderWindow* _window;

public:
    game(sf::RenderWindow* window);
    ~game();
    
    int getScore() const { return gameData.score; }
    int getRemainingMoves() const { return gameData.remainingmoves; }
    void setScore(int score) { gameData.score = score; }
    void setRemainingMoves(int remainingMoves) { gameData.remainingmoves = remainingMoves; }
    grid getgrid();
    void afficherpartie(sf::RenderWindow* win);
    void start();
    int getNbCoup();
    void incrScore();
    void incrMoves();
    void arreter(); // TODO
    void update();
    void load(std::string filename);
    void save(std::string filename);
    void relancer(); // TODO
};
