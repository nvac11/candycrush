#include "DisplayMenu.hpp"


DisplayMenu::DisplayMenu()
{
    if (!font.loadFromFile("arial.ttf")) {
        std::cerr << "Failed to load font" << std::endl;
    }
}

DisplayMenu::~DisplayMenu(){}

MenuOption DisplayMenu::displayMenu(sf::RenderWindow& window)
{
    window.clear();

    sf::Color textColorW = sf::Color::White;

    unsigned int textSize = 30;

    float x = 100.f;
    float y = 100.f;
    float spacing = 30.f;

    float rectWidth = 300.f;
    float rectHeight = 5 * textSize + 5 * spacing;

    sf::RectangleShape rect(sf::Vector2f(rectWidth, rectHeight));
    rect.setFillColor(sf::Color::Transparent);
    rect.setOutlineColor(sf::Color::White);
    rect.setOutlineThickness(2);

    rect.setPosition(x - 10.f, y - 10.f);
    window.draw(rect);

    for (int i = 0; i < 5; ++i) {
        sf::Text button;
        button.setFont(font);
        MenuOption currentOption;
        switch (static_cast<MenuOption>(i)) {
            case MenuOption::Continue:
                button.setString("Continue");
                currentOption = MenuOption::Continue;
                break;
            case MenuOption::PlayNewGame:
                button.setString("Play New Game");
                currentOption = MenuOption::PlayNewGame;
                break;
            case MenuOption::Save:
                button.setString("Save");
                currentOption = MenuOption::Save;
                break;
            case MenuOption::Load:
                button.setString("Load");
                currentOption = MenuOption::Load;
                break;
            case MenuOption::Quit:
                button.setString("Quit");
                currentOption = MenuOption::Quit;
                break;
            default:
                button.setString("Unknown Option");
                currentOption = MenuOption::None;
                break;
        }

        button.setCharacterSize(textSize);
        button.setFillColor(textColorW);
        button.setPosition(x, y);

        window.draw(button);
        y += textSize + spacing;
    }

    window.display();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                for (int i = 0; i < 5; ++i) {
                    sf::FloatRect buttonRect(x, 100.f + i * (textSize + spacing), rectWidth, textSize);
                    if (buttonRect.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        return static_cast<MenuOption>(i);
                    }
                }
            }
            if (event.type == sf::Event::Closed) {
                window.close();
                return MenuOption::Quit;
            }
        }
    }

    return MenuOption::None;  
}
