void game::start(){
        MenuOption choice = None;
        State gameState = INMENU; 
        while (_window->isOpen()) {
        sf::Event event;
        while (_window->pollEvent(event)) {    
            sf::Vector2i mousePos = sf::Mouse::getPosition(*_window); // Get mouse position in window coordinates
            sf::Vector2f worldMousePos = _window->mapPixelToCoords(mousePos); // Map window coordinates to world coordinates
            _IOevent->setMousePos(worldMousePos); // Set the world mouse position
            std::cout<< _IOevent->getMousePos().x <<  _IOevent->getMousePos().y << std::endl;

            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    _IOevent->setMouseClickedLeft(true);
                } else if (event.mouseButton.button == sf::Mouse::Right) { // Changed to Right
                    _IOevent->setMouseClickedRight(true);
                } else {
                    _IOevent->setMouseClickedLeft(false);
                    _IOevent->setMouseClickedRight(false);
                }
            } else {
                _IOevent->setMouseClickedLeft(false);
                _IOevent->setMouseClickedRight(false);
                
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
                choice = _interface->affichermenu(_window, _IOevent);
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
his this state handling correct