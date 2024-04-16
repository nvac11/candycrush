#include <iostream>
#include <vector>
#include <random>
#include <utility>
#include "grille.hpp"
#include "graphic.hpp"
#include <SFML/Graphics.hpp>

using namespace std;

int main(int argc, char const *argv[])
{
    size_t n = 10;
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");
    
    vector<vector<int>> g(n, vector<int>(n, 0));
    
    // Fill and display the grid
    g = fillGrid(g);
    for (size_t i = 0; i < g.size(); i++){
        for (size_t j = 0; j < g.size(); j++){
            g[i][j] = (i + j)%2 +1;
        }
    }
    
    int score = 0;
    bool gamerunning = true; 
    while(gamerunning) {
        cout << "score : "<< score << endl;
        
        // Clear the window
        window.clear();

        // Draw the grid
        affichergrid(&window, g);

        // Handle events
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                    gamerunning = false;  // Exit the game loop
                    break;

                case sf::Event::MouseButtonPressed:
                    cout << "mouse pressed" << endl;
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        // Get mouse position
                        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                        
                        // Create and draw a rectangle at mouse position
                        sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
                        rectangle.setPosition(mousePos.x, mousePos.y);
                        rectangle.setFillColor(sf::Color::Yellow);
                        window.draw(rectangle);
                    }
                    break;

                default:
                    break;
            }
        }

        // Display the window contents
        window.display();
    
        pair<pair<int, int>, pair<int, int>> coupcoup = getCoup();
        
        pair<int, int> c1 = coupcoup.first;
        pair<int, int> c2 = coupcoup.second;

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
        } else {
            cout << "Invalid swap. Please try again." << endl;
        }
    }
    return 0;
}
