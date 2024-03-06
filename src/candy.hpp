#pragma once
enum colors  {red , blue , green, purple};


class candy
{
private:
    colors _color;
public:
    candy();
    ~candy();
    colors getColor();
    void setColor(colors  col);
    void setRandom();
};