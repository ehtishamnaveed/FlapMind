#ifndef UI_H
#define UI_H
#include "../Header/EventHandler.h"
#include "../Header/GameManager.h"
#include "../Header/Game.h"
#include <string>
#include <chrono>
#include <thread>

namespace UI {
    class Menu {
    public:
        Menu(): Width(600), Height(600), SelectedMenu(0) {}
        // Virtual destructor
        // To ensure destructor of the derived class is called correctly
        virtual ~Menu() {}
        void drawMenu(sf::RenderWindow& window);
        void moveUp();
        void moveDown();
        int getSelectedState();
        virtual void drawBackground(sf::RenderWindow& i_window) = 0;

    protected:
        const short Width;
        const short Height;
        int SelectedMenu;

        sf::Font menuFont;
        sf::Text MenuText[3];
        sf::RectangleShape MenuBox[3];

        sf::Texture background_texture;
        sf::Sprite background_sprite;
    };

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Main Menu class
    class MainMenu : public Menu {
    public:
        MainMenu();
        void drawBackground(sf::RenderWindow& i_window) override;
    };

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Play Menu class
    class PlayMenu : public Menu {
    public:
        PlayMenu();
        void drawBackground(sf::RenderWindow& i_window) override;
    };

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Theme Menu class
    class ThemeMenu : public Menu {
    public:
        ThemeMenu();
        void drawBackground(sf::RenderWindow& i_window) override;

    private:
        std::string Themes[3];
    };

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Manager for Menus
    class MenuManager {
    public:
        MenuManager();
        // Music and FX
        void playLoadingFX();
        void playMainMenuMusic();
        void stopMainMenuMusic();

        void displayMenu(UI::Menu*& currentMenu);
        
        // Handles Specific Menu State
        void handleMenuStateChange(UI::Menu*& currentMenu);
        void handleMainMenu(UI::Menu*& currentMenu);
        void handlePlayMenu(UI::Menu*& currentMenu);
        void handleThemeMenu(UI::Menu*& currentMenu);

    private:
        Game::EventHandler EventManager;
        sf::RenderWindow window;
        Game::GameManager GameController;

        // Loading Screen Sound
        sf::SoundBuffer FXsound;
        sf::Sound LoadingFX;
    };
}

#endif