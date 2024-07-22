#include <SFML/Graphics.hpp>
#include "../Header/Game.h"
#include "../Header/UI.h"
#include "../Header/MenuManager.h"

int main() {
    // Load the Game Settings
    Game::loadConfiguration();

    // Create a pointer to MainMenu instance
    UI::Menu* currentMenu = new UI::MainMenu();

    // Create MenuManager instance
    UI::MenuManager MenuHandler;

    // Display the main menu using MenuHandler
    MenuHandler.displayMenu(currentMenu);

    // Save the Game Settings
    Game::saveConfiguration();

    // Delete the currentMenu pointer to avoid memory leaks
    delete currentMenu;

    // Return 0 to indicate successful completion
    return 0;
}
