#include <SFML/Graphics.hpp>



#include "grid.hpp"







int main()
{

    grid newgrid = grid();
    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");
    
    // Création d'un vecteur pour stocker les rectangles
    std::vector<sf::RectangleShape> rectangles;

    // Ajout des rectangles au vecteur
    for (int i = 0; i < 10; ++i) {
        sf::RectangleShape rectangle(sf::Vector2f(50.f, 50.f)); // Taille du rectangle
        rectangle.setPosition(i * 60.f, 100.f); // Position du rectangle (espacement horizontal de 60 pixels)
        rectangle.setFillColor(sf::Color(100 + i * 15, 50 + i * 15, 200 - i * 10)); // Couleur du rectangle (variant avec i)
        rectangles.push_back(rectangle); // Ajout du rectangle au vecteur
    }

 
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        // Gestion de l'erreur si la police n'a pas pu être chargée
        return EXIT_FAILURE;
    }
    sf::Text text;
    text.setFont(font); // Définition de la police de caractères
    text.setString("Hello, SFML!"); // Définition du texte
    text.setCharacterSize(24); // Définition de la taille des caractères (en pixels)
    text.setFillColor(sf::Color::Red); // Définition de la couleur du texte
    text.setPosition(400.f, 400.f); // Définition de la position du texte sur la fenêtre

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        for (const auto& rectangle : rectangles) {
            window.draw(rectangle);
        }    
        window.draw(text);
        window.display();
    }

    return 0;
}
