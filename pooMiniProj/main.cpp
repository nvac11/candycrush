#include "app.hpp"

using namespace std;
int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "Candy Crush");
    app application = app(&window, 5);
    application.start(INMENU);
    return 0;
}
