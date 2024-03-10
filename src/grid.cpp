#include "grid.hpp"
#include <random>
colors getRandomEnumColor() {
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, static_cast<int>(colors::COUNT) - 1);
    
    return static_cast<colors>(dist(gen));
}

grid::grid(int size) : _grid(size, vector<candy*>(size, nullptr)) {

    for (int i=0; i < _grid.size(); i++){
        for (int j=0; j < _grid.size(); j++){
            _grid[i][j] = new candy(getRandomEnumColor());
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