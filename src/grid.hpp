#pragma once
#include "candy.hpp"
#include <vector>
#include <iostream>
using namespace std;

class grid
{
private:
    vector<vector<candy *>> _grid;

public:
    bool isSolvable();
    bool isValidMove(); 
    void candydestruct(); 
    void candyFall();
    grid(int size = 10);
    ~grid();
};
