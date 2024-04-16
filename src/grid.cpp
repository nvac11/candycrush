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



    bool grid::isSolvable(){
        return true; //TODO 
    };
    
    bool grid::isValidMove(int i, int j, int k, int l){
        // on regarde si quand on permute deux colones il y a un destruction sur la grille
        vector<vector<bool>> tmp ;
        vector<vector<candy *>> grid ;
        
        for (int i = 0; i < grid.size() ; i++){
            for (int j = 0; j < grid.size() ; j++)
            {
                if (grid.at(i).at(j)->getColor() == grid.at(i+1).at(j)->getColor() && grid.at(i - 1).at(j)->getColor() == grid.at(i).at(j)->getColor()){
                    tmp.at(i).at(j) = true;
                } else {
                    tmp.at(i).at(j) = false;
                }
                if (grid.at(i).at(j)->getColor() == grid.at(i).at(j+1)->getColor() && grid.at(i).at(j-1)->getColor() == grid.at(i).at(j)->getColor()){
                    tmp.at(i).at(j) = true;
                } else {
                    tmp.at(i).at(j) = false;
                }
            }            
        }

    }; 

    void grid::candydestruct(){
        //TODO
    }; 
    
    void grid::candyFall(){
        vector<vector<bool>> tmp ;   

        for (int i = 0; i < _grid.size() ; i++){
            for (int j = 0; j < _grid.size() ; j++)
            {
                if (_grid.at(i).at(j)->getColor() == _grid.at(i+1).at(j)->getColor() && _grid.at(i - 1).at(j)->getColor() == _grid.at(i).at(j)->getColor()){
                    tmp.at(i).at(j) = true;
                } else {
                    tmp.at(i).at(j) = false;
                }
                if (_grid.at(i).at(j)->getColor() == _grid.at(i).at(j+1)->getColor() && _grid.at(i).at(j-1)->getColor() == _grid.at(i).at(j)->getColor()){
                    tmp.at(i).at(j) = true;
                } else {
                    tmp.at(i).at(j) = false;
                }
            }            
        }
        for (size_t i = 0; i < _grid.size(); i++){
            for (size_t j = 0; j < _grid.size(); j++){
                if (tmp.at(i).at(j)){
                    _grid.at(i).at(j)->setColor(colors::WHITE);
                }
            }    
        }
                
    };

void grid::debugDisplay(){
    for (const auto & j : _grid){
        for(const auto & i : j){
            std::cout << i->colorToString() << " ";            
        }
        std::cout << std::endl;
    }
}