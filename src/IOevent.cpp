#include "IOevent.hpp"
IOevent::IOevent(sf::RenderWindow * window)
{
 _window = window;
}

sf::Vector2f IOevent::getMousePos(){
    return _MouseCoord;
}
void IOevent::setMousePos(sf::Vector2f coords){
    _MouseCoord = coords;
}



bool IOevent::isMouseClickedLeft(){        
    return _LeftMouseClicked;
}

void IOevent::setMouseClickedLeft(bool v){
    _LeftMouseClicked = v;
}

bool IOevent::isMouseClickedRight(){        
    return _RightMouseClicked;
}

void IOevent::setMouseClickedRight(bool v){
    _RightMouseClicked = v;
}