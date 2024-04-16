#pragma once



#include <vector>
#include <random>
#include <utility>
using namespace std;

class Grid : public vector<vector<int>>
{
private:
    int n;  
    int score;
public:
    Grid(int size, int score, vector<vector<int>> ret) : n(size), score(score), vector<vector<int>>(ret) {};
    ~Grid(){};
    Grid(const Grid& other) : n(other.n), score(other.score), vector<vector<int>>(other){};
    bool isValid(pair<int, int> c1, pair<int, int> c2);
    Grid destruct();
    Grid fall();
    Grid fill();
    bool canBeDestruct();
    bool isSolvable();
    void display();
    Grid swap(pair<int, int> c1, pair<int, int> c2);
};





bool isValid(vector<vector<int>> g, pair<int, int> c1, pair<int, int> c2);
vector<vector<int>> destructGrid(vector<vector<int>> g , int & score);
vector<vector<int>> fallGrid(vector<vector<int>> g);
vector<vector<int>> fillGrid(vector<vector<int>> g);
bool canBeDestruct(vector<vector<int>> g);
bool isSolvable(vector<vector<int>> g);
void displayMat2d(vector<vector<int>> g);
pair<pair<int, int>, pair<int, int>> getCoup();
int getRandomInt(int min, int max);