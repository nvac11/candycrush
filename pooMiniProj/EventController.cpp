#include "EventController.hpp"
#include "GridDisplay.hpp"
#include <SFML/Graphics.hpp>
#include <iostream>

EventController::EventController(GridDisplay *g) : gdisplay(g), clickedPairs({{-1, -1}, {-1, -1}}) {}

bool EventController::handleEvent(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {

            sf::Vector2f mousePos = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
            gdisplay->processRectClicked(mousePos, clickedPairs);
        }
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
            return true;
        }
    }
    return false;
}

std::pair<std::pair<int, int>, std::pair<int, int>>& EventController::getClickedPairs() {
    return clickedPairs;
}

bool EventController::hasTwoClicked() const {
    return clickedPairs.first != std::make_pair(-1, -1) && clickedPairs.second != std::make_pair(-1, -1);
}

bool EventController::noRectClicked() const {
    return clickedPairs.first == std::make_pair(-1, -1) && clickedPairs.second == std::make_pair(-1, -1);
}

void EventController::resetClicked() {
    clickedPairs = std::make_pair(std::make_pair(-1, -1), std::make_pair(-1, -1));
}