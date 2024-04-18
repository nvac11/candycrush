
#include "grille.hpp"
#include <iostream>
#define COLORMINID 1 // numbers of total colors (replaced at compile time)
#define COLORMAXID 5 //


using namespace std;



int getRandomInt(int min, int max)
{
    std::random_device rd;  
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distrib(min, max); 
    return distrib(gen);  
}

pair<pair<int, int>, pair<int, int>> getCoup() {
    pair<int, int> c1 ;
    pair<int, int> c2 ;

    cout << "entrer coup 1 :" << endl;
    cin >> c1.first;
    cin >> c1.second;
    cout << "entrer coup 2 :" << endl;
    cin >> c2.first;
    cin >> c2.second;
    return {c1,c2};
}

void displayMat2d(vector<vector<int>> g){
    for (size_t i = 0; i < g.size(); i++){
        for (size_t j = 0; j < g.size(); j++){
            cout << g.at(i).at(j) << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> destructGrid(vector<vector<int>> g, int& score) {
    int n = g.size();
    vector<vector<bool>> mask(n, vector<bool>(n, false));
    vector<vector<int>> ret(n, vector<int>(n, 0));  
    
    // checking if they are 3 next to each other on each lines
    for (size_t i = 1; i < n - 1; i++) { 
        for (size_t j = 0; j < n; j++) {
            if (g[i][j] == g[i + 1][j] && g[i][j] == g[i - 1][j]) {
                mask[i][j] = true;
                mask[i+1][j] = true;
                mask[i-1][j] = true;
            }
        }
    }

    // checking if they are 3 next to each other on each columns
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 1; j < n - 1; j++) {
            if (g[i][j] == g[i][j + 1] && g[i][j] == g[i][j - 1]) {
                mask[i][j] = true;
                mask[i][j+1] = true;
                mask[i][j-1] = true;
            }
        }
    }

    // populate ret and calculate score
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n; j++) {
            if (mask[i][j]) {
                score++;
                ret[i][j] = 0;
            } else {
                ret[i][j] = g[i][j];
            }
        }
    }
    return ret;
}



vector<vector<int>> fallGrid(vector<vector<int>> g) {
    int n = g.size();
    vector<vector<int>> ret(n, vector<int>(n, 0)); 
    
    for (size_t j = 0; j < n; j++) {
        int pos = n - 1; // position to place the next non-zero element
        // shift elements downward
        for (int i = n - 1; i >= 0; i--) {
            if (g[i][j] != 0) {
                ret[pos][j] = g[i][j];
                pos--;
            }
        }
        // fill zeros
        for (int i = pos; i >= 0; i--) {
            ret[i][j] = 0;
        }
    }
    return ret;
}

vector<vector<int>> fillGrid(vector<vector<int>> g){
    int n = g.size();
    
    vector<vector<int>> ret(n, vector<int>(n, 0)); 
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if( g[i][j] == 0){
                ret[i][j] = getRandomInt(COLORMINID,COLORMAXID);
            } else {
                ret[i][j] = g[i][j];
            }
        }
    }
    return ret;
}

bool canBeDestruct(vector<vector<int>> g){
    int trashC = 0;
    int n = g.size();
    bool all = false;
    auto destructedGrid = destructGrid(g, trashC);
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (destructedGrid[i][j] != g[i][j]){
                all = true;
            }
        }
    }
    return all;
}
bool isSolvable(vector<vector<int>> g) {
    int n = g.size();

    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n; j++) {
            swap(g[i][j], g[i + 1][j]); 
            if (canBeDestruct(g)) {
                return true;  // found a solution on col 
            }
            swap(g[i][j], g[i + 1][j]); // swap back 
        }
    }

    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < n - 1; j++) {
            swap(g[i][j], g[i][j + 1]); 
            if (canBeDestruct(g)) {
                return true;  // found a solution on row
            }
            swap(g[i][j], g[i][j + 1]); // swap back
        }
    }

    return false;  // No solution found
}

bool isValid(vector<vector<int>> g, pair<int, int> c1, pair<int, int> c2) {
    int n = g.size();

    if (abs(c1.first - c2.first) + abs(c1.second - c2.second) != 1) {
        return false;
    }

    swap(g[c1.first][c1.second], g[c2.first][c2.second]);
    //displayMat2d(g);
    return canBeDestruct(g);
}


/*
void test(vector<vector<int>> g){
    g = fillGrid(g);
    score = 0;
    displayMat2d(g);
    cout << "\n";
    displayMat2d(destructGrid(g, score));
    cout << "\n";
    displayMat2d(fallGrid(destructGrid(g, score)));
    cout << "\n";
    displayMat2d(fillGrid(fallGrid(destructGrid(g, score))));
    
    //damier 
    for (size_t i = 0; i < g.size(); i++){
        for (size_t j = 0; j < g.size(); j++){
            g[i][j] = (i + j)%2 +1;
        }
    }
    
    
    //not solvable 
    int c = 0;
    for (size_t i = 0; i < g.size(); i++){
        for (size_t j = 0; j < g.size(); j++){
            g[i][j] = c +1;
            c++;
        }
    }
    
    cout << "\n";
    displayMat2d(g);
    cout << "\n";
    cout << canBeDestruct(g) << endl;
    cout << isSolvable(g);
    cout << "\n";
    displayMat2d(g);
    
}
*/
