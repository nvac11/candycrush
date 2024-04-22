
    
#include "GridDisplay.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>
GridDisplay::GridDisplay(int n ) : n(n),gInner(n, std::vector<int>(n, 0)) {
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
            rectangle.setPosition(j * 60.f, i * 60.f);
            rectangle.setFillColor(intToSFMLColor(gInner[i][j]));
            rectangles.push_back(rectangle);
        }
    }

    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }

    scoreText.setFont(font);
    scoreText.setCharacterSize(24); 
    scoreText.setFillColor(sf::Color::White);
    scoreText.setPosition(500, 100);
}

void GridDisplay::processRectClicked(sf::Vector2f mousePos, std::pair<std::pair<int, int>, std::pair<int, int>>& clickedPairs) {
    for (int i = 0; i < rectangles.size(); ++i) {
        if (rectangles[i].getGlobalBounds().contains(mousePos)) {
            if (clickedPairs.first == std::make_pair(-1, -1)) {
                std::cout << "clicked on first" << std::endl; 
                int rowIndex = i / n;  
                int colIndex = i % n;
                clickedPairs.first = std::make_pair(rowIndex, colIndex);
                rectangles[i].setFillColor(sf::Color::White);
            } else if (clickedPairs.second == std::make_pair(-1, -1)) {
                std::cout << "clicked on second" << std::endl; 
                int rowIndex = i / n;
                int colIndex = i % n;
                clickedPairs.second = std::make_pair(rowIndex, colIndex);
                rectangles[i].setFillColor(sf::Color::White);
            } else {
                rectangles[clickedPairs.first.first * n + clickedPairs.first.second].setFillColor(intToSFMLColor(gInner[clickedPairs.first.first][clickedPairs.first.second]));
                rectangles[clickedPairs.second.first * n + clickedPairs.second.second].setFillColor(intToSFMLColor(gInner[clickedPairs.second.first][clickedPairs.second.second]));
                clickedPairs = std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
            }
        }
    }
}

void GridDisplay::updateScore(int score,int remainingmoves) {
    scoreText.setString("Score: " + std::to_string(score) + "\n" + "Remaining moves: " + std::to_string(remainingmoves));
}

sf::Color GridDisplay::intToSFMLColor(int colorCode) {
    switch(colorCode) {
        case 0:
            return sf::Color::White;
        case 1:
            return sf::Color::Magenta;
        case 2:
            return sf::Color::Red;
        case 3:
            return sf::Color::Green;
        case 4:
            return sf::Color::Blue;
        case 5:
            return sf::Color::Yellow;
        default:
            return sf::Color::Transparent;
    }
}

void GridDisplay::updateRectGrid(std::vector<std::vector<int>> g) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            gInner[i][j] = g[i][j];
            rectangles[i * n + j].setFillColor(intToSFMLColor(g[i][j]));
        }
    }
}


void GridDisplay::displayGrid(sf::RenderWindow& window) const {
    window.clear();
    for (const auto& rectangle : rectangles) {
        window.draw(rectangle);
    }
    window.draw(scoreText);
    window.display();
}


