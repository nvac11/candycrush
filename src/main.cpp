#include <SFML/Graphics.hpp>








int main()
{
    // Création de la fenêtre SFML
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML Example");

    // Boucle principale
    while (window.isOpen())
    {
        // Gestion des événements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        // Effacement de la fenêtre (la rendant vide)
        window.clear();

        // Affichage de la fenêtre (montrant ainsi la fenêtre vide)
        window.display();
    }

    return 0;
}
