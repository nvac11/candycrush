#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <vector>
#include <utility>
#include "GridDisplay.hpp"


// Author : Conrad

class EventController {
private:
    GridDisplay * gdisplay;
    std::pair<std::pair<int, int>, std::pair<int, int>> clickedPairs;

public:
    EventController(GridDisplay *g);
    bool handleEvent(sf::RenderWindow& window);
    std::pair<std::pair<int, int>, std::pair<int, int>>& getClickedPairs();
    bool hasTwoClicked() const;
    void resetClicked();
    bool noRectClicked() const;
};
