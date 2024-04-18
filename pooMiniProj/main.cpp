#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>  
#include "EventController.hpp"
#include "GridDisplay.hpp"
#include "grille.hpp"

using namespace std;
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Candy Crush");
    int n = 4;
    GridDisplay gridDisplay(n);
    EventController eventController(&gridDisplay);

    int score = 0;
    bool gamerunning = true; 

    vector<vector<int>> g = fillGrid(vector<vector<int>>(n, vector<int>(n, 0))); 
    do {
        g = destructGrid(g, score);
        g = fallGrid(g);
        g = fillGrid(g);

    } while(canBeDestruct(g));
    score = 0;
    auto lastclicked = std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
    gridDisplay.updateRectGrid(g);
    gridDisplay.updateScore(score);
    while (window.isOpen() && gamerunning) {
        eventController.handleEvent(window);
        gridDisplay.displayGrid(window);

        if (eventController.hasTwoClicked()) {
            auto clickedIndices = eventController.getClickedPairs();
            pair<int, int> c1 = clickedIndices.first;
            pair<int, int> c2 = clickedIndices.second;
            if( lastclicked != clickedIndices){
            if ( isValid(g, c1, c2)) {
                lastclicked = clickedIndices;
                cout << "c1 : " << c1.first << "," << c1.second << endl;
                cout << "c2 : " << c2.first << "," << c2.second << endl;
                
                swap(g[c1.first][c1.second], g[c2.first][c2.second]);
                do {
                    g = destructGrid(g, score);
                    g = fallGrid(g);
                    g = fillGrid(g);
                    gridDisplay.updateScore(score);
                    gridDisplay.updateRectGrid(g);
                } while(canBeDestruct(g) && isSolvable(g));
                if (!isSolvable(g)) {
                    gamerunning = false;
                }
            } else {
                cout << "invalid move" << endl;
            }
            }
        } 
    }
    return 0;
}
