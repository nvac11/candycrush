#pragma once
enum colors  {RED , BLUE , GREEN, PURPLE};


class candy
{
private:
    colors _color;
public:
    candy(colors col);
    ~candy();
    colors getColor();
    void setColor(colors  col);
    void setRandom();
};