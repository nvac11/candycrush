#include <SFML/Graphics.hpp>
#include <iostream>
#include <unordered_map>
#include <utility>  
#include "../gridfunc/grille.hpp"
class EventController {
private:
    std::unordered_map<int, std::pair<int, int>> clickedIndices;

public:
    void handleEvent(sf::RenderWindow& window, std::vector<sf::RectangleShape>& rectangles) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                    for (int i = 0; i < rectangles.size(); ++i) {
                        if (rectangles[i].getGlobalBounds().contains(mousePos)) {
                            if (clickedIndices.size() < 2) {
                                if (clickedIndices.find(i) == clickedIndices.end()) {
                                    int rowIndex = i / 3;  
                                    int colIndex = i % 3;
                                    clickedIndices[i] = std::make_pair(rowIndex, colIndex);
                                    rectangles[i].setFillColor(sf::Color::White);
                                } else {
                                    clickedIndices.erase(i);
                                    rectangles[i].setFillColor(sf::Color::Blue);
                                }
                            } else {
                                for (const auto& pair : clickedIndices) {
                                    rectangles[pair.first].setFillColor(sf::Color::Blue);
                                }
                                clickedIndices.clear();
                            }
                        }
                    }
                }
            }
        }
    }

    bool hasTwoClicked() const {
        return clickedIndices.size() == 2;
    }

    bool noRectClicked() const {
        return clickedIndices.empty();
    }

    std::pair<std::pair<int, int>, std::pair<int, int>> getClickedIndices() const {
        if (clickedIndices.size() == 2) {
            auto it = clickedIndices.begin();
            std::pair<int, int> firstPair = it->second;
            ++it;
            std::pair<int, int> secondPair = it->second;
            return std::make_pair(firstPair, secondPair);
        }
        return std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
    }
};

class GridDisplay {
public:
    void displayGrid(sf::RenderWindow& window, const std::vector<sf::RectangleShape>& rectangles) const {
        window.clear();
        for (const auto& rectangle : rectangles) {
            window.draw(rectangle);
        }
        window.display();
    }
};

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Grid Example");

    size_t n = 10;
    
    vector<vector<int>> g(n, vector<int>(n, 0));
    
    g = fillGrid(g);
    for (size_t i = 0; i < g.size(); i++){
        for (size_t j = 0; j < g.size(); j++){
            g[i][j] = (i + j) % 2 + 1;
        }
    }

    std::vector<sf::RectangleShape> rectangles;

    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < g[i].size(); j++) {
            sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f));
            rectangle.setPosition(j * 60.f, i * 60.f);
            rectangle.setFillColor(sf::Color::Blue);
            rectangles.push_back(rectangle);
        }
    }

    EventController eventController;
    GridDisplay gridDisplay;
    int score = 0;
    bool gamerunning = true; 
  
    while (window.isOpen() && gamerunning) {
        eventController.handleEvent(window, rectangles);
        gridDisplay.displayGrid(window, rectangles);


        if (eventController.hasTwoClicked()) {
            auto clickedIndices = eventController.getClickedIndices();
            std::cout << "Indices of clicked elements:" << std::endl;
            std::cout << "First clicked: i = " << clickedIndices.first.first << ", j = " << clickedIndices.first.second << std::endl;
            std::cout << "Second clicked: i = " << clickedIndices.second.first << ", j = " << clickedIndices.second.second << std::endl;
        } else if (eventController.noRectClicked()) {
            std::cout << "No rectangles are clicked." << std::endl;
        }
    }

    return 0;
}
