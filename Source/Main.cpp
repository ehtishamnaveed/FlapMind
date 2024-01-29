#include <SFML/Graphics.hpp>
// #include "../Header/GameManager.h"
#include "../Header/Game.h"
#include "../Header/UI.h"

int main() {
    // sf::RenderWindow window(sf::VideoMode(Game::Screen::screenWidth, Game::Screen::screenHeight), "Flappy Birds");
    // window.setFramerateLimit(30);

    UI::Menu* currentMenu = new UI::MainMenu();

    UI::MenuManager MenuHandler;
    MenuHandler.displayMenu(currentMenu);

    return 0;
}
