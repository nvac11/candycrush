#include "grid.hpp"

grid::grid(int size) : _grid(size, vector<candy*>(size, nullptr)) {
    for (int i=0; i < _grid.size(); i++){
        for (int j=0; j < _grid.size(); j++){
            _grid[i][j] = new candy(BLUE); 
        }
    }
}

grid::~grid(){
    for (int i=0; i < _grid.size(); i++){
        for (int j=0; j < _grid.size(); j++){
            delete _grid[i][j]; 
        }
    }
}



    bool isSolvable(){
        return true; //TODO 
    };
    bool isValidMove(){
        return true; //TODO
        }; 
    void candydestruct(){
        //TODO
    }; 
    void candyFall(){
        //TODO
    };

   void grid::debugDisplay(){
    for (const auto & j : _grid){
        for(const auto & i : j){
            std::cout << i;            
        }
        std::cout << std::endl;
    }
}