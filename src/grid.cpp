#include "grid.hpp"


grid::grid(int size = 10)
{
// need to init the vector with zeros


    for (int i=0; i < size; i++){
        for (int j=0; j < size; j++){
            _grid[i][j] = new candy;
        }
    }
}

grid::~grid()
{
    for (int i=0; i < _grid.size(); i++){
        for (int j=0; j < _grid.size(); j++){
            delete _grid[i][j]; 
        }
    }
}
