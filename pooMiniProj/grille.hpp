#pragma once



#include <vector>
#include <random>
#include <utility>
using namespace std;






bool isValid(vector<vector<int>> g, pair<int, int> c1, pair<int, int> c2);
vector<vector<int>> destructGrid(vector<vector<int>> g , int & score);
vector<vector<int>> fallGrid(vector<vector<int>> g);
vector<vector<int>> fillGrid(vector<vector<int>> g);
bool canBeDestruct(vector<vector<int>> g);
bool isSolvable(vector<vector<int>> g);
void displayMat2d(vector<vector<int>> g);
pair<pair<int, int>, pair<int, int>> getCoup();
int getRandomInt(int min, int max);