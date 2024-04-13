#include <SFML/Graphics.hpp>


bool checkCollision(const sf::Vector2f& point, const sf::FloatRect& rect) {
    return rect.contains(point);
}