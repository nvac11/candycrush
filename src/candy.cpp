#include "candy.hpp"


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
