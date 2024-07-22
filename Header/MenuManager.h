#ifndef MENUMANAGER_H
#define MENUMANAGER_H
#include "../Header/EventHandler.h"
#include "../Header/UI.h"
#include "../Header/Game.h"

namespace UI {
	// Manager for Menus
    class MenuManager {
    public:
        MenuManager();
        // Display the Project Group Logo for 3 seconds
        void displayLogo();

        // Music
        void playMainMenuMusic();
        void stopMainMenuMusic();

        void displayMenu(UI::Menu*& currentMenu);
        
        // Handles Specific Menu State
        void handleMenuStateChange(UI::Menu*& currentMenu);
        void handleMainMenu(UI::Menu*& currentMenu);
        void handlePlayMenu(UI::Menu*& currentMenu);
        void handleThemeMenu(UI::Menu*& currentMenu);
        void handleControlsMenu(UI::Menu*& currentMenu);

    private:
        Game::EventHandler EventManager;
        sf::RenderWindow window;
        Game::GameManager GameController;

        sf::Music mainMenuMusic;
    };
}

#endif