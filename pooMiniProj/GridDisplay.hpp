#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;



// Author : Noé

class GridDisplay {
private:
    std::vector<sf::RectangleShape> rectangles;
    std::vector<std::vector<int>> gInner;
    int n;
    sf::Font font;
    sf::Text scoreText;
    
public:
    GridDisplay(int n );
    void processRectClicked(sf::Vector2f mousePos, std::pair<std::pair<int, int>, std::pair<int, int>>& clickedPairs);
    void displayGrid(sf::RenderWindow& window) const;
    void updateRectGrid(vector<vector<int>> g);
    void updateScore(int score, int remainingmove);
    sf::Color intToSFMLColor(int colorCode);
};