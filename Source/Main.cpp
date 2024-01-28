#include <SFML/Graphics.hpp>
#include "../Header/GameManager.h"
#include "../Header/Game.h"
#include "../Header/UI.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(Game::Screen::screenWidth, Game::Screen::screenHeight), "Flappy Birds");
    window.setFramerateLimit(30);
    
    sf::Texture background_texture;
    sf::Sprite background_sprite;

    Game::GameManager gameController;
    UI::MainMenu Menu;

    while (window.isOpen()) {
        window.clear();

        sf::Event event;
        if (window.pollEvent(event)){
            switch (event.type) {
                // Close the window if the close button is pressed
                case sf::Event::Closed:
                    window.close();
                    break;

                // Handle key presses
                case sf::Event::KeyPressed:

                    switch (event.key.code) {
                        // Start the game when the Enter key is pressed
                        case sf::Keyboard::Enter:
                            // gameController.runGame(window);
                            break;

                        case sf::Keyboard::Up:
                            Menu.moveUp();
                            break;

                        case sf::Keyboard::Down:
                            Menu.moveDown();
                            break;
                    }
                    break;
            }
        }
        Game::Screen::drawBackground(window,background_texture,background_sprite,"MainScreen.png");
        // Draw the menu after handling events
        Menu.drawMenu(window);

        // Display the window
        window.display();
    }
    return 0;
}
