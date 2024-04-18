#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
using namespace std;
class GridDisplay {
private:
    std::vector<sf::RectangleShape> rectangles;
    std::vector<std::vector<int>> gInner;
    int n;

public:
    GridDisplay(int n );

    void processRectClicked(sf::Vector2f mousePos, std::pair<std::pair<int, int>, std::pair<int, int>>& clickedPairs);
    void displayGrid(sf::RenderWindow& window) const;
    void updateRectGrid(vector<vector<int>> g);
    sf::Color intToSFMLColor(int colorCode);
};
