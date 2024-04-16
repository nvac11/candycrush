#include <SFML/Graphics.hpp>
#include <vector>


using namespace std;
sf::Color getColorForValue(int value);
void affichergrid(sf::RenderWindow *window, vector<vector<int>> g);