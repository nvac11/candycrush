#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>  
#include "EventController.hpp"
#include "GridDisplay.hpp"
#include "grille.hpp"
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Candy Crush");
    int n = 10;
    GridDisplay gridDisplay(n);
    EventController eventController(&gridDisplay);

    int score = 0;
    bool gamerunning = true; 

    vector<vector<int>> g = fillGrid(vector<vector<int>>(n, vector<int>(n, 0))); // Directly initialize g with filled grid
    do {
        g = destructGrid(g, score);
        g = fallGrid(g);
        g = fillGrid(g);
    } while(canBeDestruct(g));

    gridDisplay.updateRectGrid(g);

    while (window.isOpen() && gamerunning) {
        gridDisplay.displayGrid(window);

        eventController.handleEvent(window);
        
        if (eventController.hasTwoClicked()) {
            auto clickedIndices = eventController.getClickedPairs();
        
            pair<int, int> c1 = clickedIndices.first;
            pair<int, int> c2 = clickedIndices.second;

            if (isValid(g, c1, c2)) {
                swap(g[c1.first][c1.second], g[c2.first][c2.second]);
                
                do {
                    g = destructGrid(g, score);
                    g = fallGrid(g);
                    g = fillGrid(g);
                } while(canBeDestruct(g) && isSolvable(g));
                
                if (!isSolvable(g)) {
                    gamerunning = false;
                }
            }    
            gridDisplay.updateRectGrid(g);

        } else if (eventController.noRectClicked()) {
            std::cout << "No rectangles are clicked." << std::endl;
        }
    }
    return 0;
}
