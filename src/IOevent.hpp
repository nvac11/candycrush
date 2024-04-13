#include <SFML/Graphics.hpp>

class IOevent
{
private:
    sf::RenderWindow * _window;
    sf::Vector2f _MouseCoord ;
    bool _LeftMouseClicked;
    bool _RightMouseClicked;
public:
    IOevent(sf::RenderWindow * window);
    ~IOevent();
    sf::Vector2f getMousePos();
    void setMousePos(sf::Vector2f coords);
    bool isMouseClickedLeft();
    void setMouseClickedLeft(bool v);
    bool isMouseClickedRight();        
    void setMouseClickedRight(bool v);
};
