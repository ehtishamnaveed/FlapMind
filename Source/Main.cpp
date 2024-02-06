#include <SFML/Graphics.hpp>
#include "../Header/Game.h"
#include "../Header/UI.h"

int main() {
    Game::loadConfiguration();

    UI::Menu* currentMenu = new UI::MainMenu();

    UI::MenuManager MenuHandler;
    MenuHandler.displayMenu(currentMenu);

    return 0;
}
