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
    bool isSolvable(); 
    bool isValidMove(int i, int j, int k, int l); 
    void candydestruct();
    void candyFall(); 
    void debugDisplay();
    grid(int size = 10);
    ~grid();
};
