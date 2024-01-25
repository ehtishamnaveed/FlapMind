#include <SFML/Graphics.hpp>
#include "../Header/GameManager.h"
#include "../Header/Game.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(Game::Screen::screenWidth, Game::Screen::screenHeight), "Flappy Birds");
    
    sf::Texture background_texture;
    sf::Sprite background_sprite;

    Game::GameManager gameController;

    // Draw the MainScreen initially
    Game::Screen::drawScreen(window,background_texture,background_sprite,"MainScreen.png");
    window.display();

    sf::Event event;
    while (window.isOpen()) {
        if (window.pollEvent(event)) {
            gameController.eventHandler(window,event);
        }

        if (Game::gameState) {
            // Draw the background and run the game
            Game::Screen::drawScreen(window,background_texture,background_sprite,"background.png");
            gameController.runGame(window);
            window.display();
        }
    }

    return 0;
}
