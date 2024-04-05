#include "game.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include "candy.hpp"
#include "interface.hpp"


    game::game(sf::RenderWindow *window) {
        _window = window;
        _IOevent = new IOevent(_window);
        _grid = new grid();
        _interface = new interface();
    }

    game::~game() {
        delete _grid;         
        delete _interface;    
}
    int game::getScore(){
        return gameData.score;
    }
    int game::getNbCoup(){
        return gameData.remainingmoves;
    }
    void game::incrScore(){
        gameData.score++;
    }
    void game::incrMoves(){
        gameData.remainingmoves++;
    }
    grid game::getgrid(){
        return *_grid;
    }
    void game::afficherpartie(sf::RenderWindow * win)
    {
        _interface->afficherscore(win, to_string(5));
        _interface->affichergrid(win, _grid);
    }
        
    void game::arreter(){};

    void game::start(){
        MenuOption choice = None;
        State gameState = INMENU; 
        while (_window->isOpen()) {
            sf::Event event;
            while (_window->pollEvent(event)) {
                    
                sf::Vector2i mousePos = sf::Mouse::getPosition();
                _IOevent->setMousePos(mousePos);
                if (event.type == sf::Event::MouseButtonPressed) {
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        _IOevent->setMouseClickedLeft(true);
                    } else if (event.mouseButton.button == sf::Mouse::Left) {
                        _IOevent->setMouseClickedRight(true);
                    } else {
                        _IOevent->setMouseClickedLeft(false);
                        _IOevent->setMouseClickedRight(false);
                    } 
                }
                if (event.type == sf::Event::Closed)
                    _window->close();
            }

        _window->clear();
        switch (gameState)
        {
            case INGAME:
                this->afficherpartie(_window);
                break;
            case INMENU:
                MenuOption choice = _interface->affichermenu(_window, _IOevent);
                break;
            case NONE:
                _window->close();
                break;
            default:
                break;
        }

        switch (choice) {
            case MenuOption::Continue:
                gameState = INGAME;
                break;
            case MenuOption::PlayNewGame:
                gameState = INGAME;
                break;
            case MenuOption::Save:
                this->save("save");
                break;
            case MenuOption::Load:
                this->load("save");
                break;
            case MenuOption::Quit:
                gameState = NONE;
                break;
            case MenuOption::None:
                break;
            default:
                break;
            }
        _window->display();
        }

    };


    std::string enumToStr(colors color)
    {
        switch(color) {
            case RED:
                return "R";
                
            case BLUE:
                return "B";
                
            case GREEN:
                return "G";
                
            case PURPLE:
                return "P";
                
            default:
                return "W";
        }
    }

colors strToEnum(const std::string& s) {
    if (s == "R") {
        return colors::RED;
    } else if (s == "B") {
        return colors::BLUE;
    } else if (s == "G") {
        return colors::GREEN;
    } else if (s == "P") {
        return colors::PURPLE;
    } else {
        return colors::WHITE;
    }
}
void game::update(){
    _grid->candydestruct();
}
void game::load(std::string filename) {
    std::ifstream infile(filename); 
    
    if (!infile.is_open()) {
        std::cerr << "Error: Unable to open file for reading!" << std::endl;
        return;
    }

    std::string line;
    std::cout << "Data loaded successfully from: " << filename << std::endl;
    
    for (int i = 0; i < _grid->_grid.size(); i++) {
        std::getline(infile, line); 
        
        for (int j = 0; j < _grid->_grid[i].size(); j++) {
            colors c = strToEnum(std::string(1, line[j]));
            _grid->_grid[i][j]->setColor(c);
        }
    }

    infile.close(); 
}


    void game::save(std::string filename){
        std::ofstream outfile;
        std::ifstream infile;
        
        outfile.open(filename); 
        if (outfile.is_open()) {
            
            for (int i = 0; i < _grid->_grid.size(); i++)
            {
                std::string s("");
                for (int j = 0; j < _grid->_grid.size(); j++)
                {
                    s += enumToStr(_grid->_grid[i][j]->getColor()) ;
                }
                outfile << s << "\n";
            }
            
            outfile.close(); 
            std::cout << "Data  written succesfully : " << filename << std::endl;
            
            } else {
                std::cerr << "Error: Unable to open file for writing!" << std::endl;
            }
        };

    void game::relancer(){}; 