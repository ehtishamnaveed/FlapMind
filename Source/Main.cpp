#include <SFML/Graphics.hpp>
#include "../Header/Game.h"
#include "../Header/UI.h"

int main() {
    // Load the Game Settings
    Game::loadConfiguration();

    UI::Menu* currentMenu = new UI::MainMenu();

    UI::MenuManager MenuHandler;
    MenuHandler.displayMenu(currentMenu);

    return 0;
}
