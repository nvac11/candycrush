#include "candy.hpp"
#include <string>
#include <iostream>

candy::candy(colors col)
{
    _color = col;
}

candy::~candy()
{
}

colors candy::getColor() {
    return _color;
}
void candy::setColor(colors col) {
    _color = col;
}
void candy::setRandom(){
    
}

std::string candy::colorToString() {
        switch (_color) {
            case colors::RED:    return "RED    ";
            case colors::BLUE:   return "BLUE   ";
            case colors::GREEN:  return "GREEN  ";
            case colors::PURPLE: return "PURPLE ";
            case colors::WHITE:  return "WHITE  ";
            default:             return "UNKNOWN";
        }
    }
