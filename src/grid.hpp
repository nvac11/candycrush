#pragma once
#pragma once

#include "candy.hpp"
#include <vector>
#include <iostream>
using namespace std;

class grid
{
private:
public:
    vector<vector<candy *>> _grid;
    bool isSolvable(); // TODO
    bool isValidMove(); // TODO
    void candydestruct();// TODO
    void candyFall(); // TODO
    void debugDisplay();
    grid(int size = 10);
    ~grid();
};
