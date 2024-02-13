#ifndef UI_H
#define UI_H
#include "../Header/EventHandler.h"
#include "../Header/GameManager.h"
#include "../Header/Game.h"
#include <string>
#include <thread>

namespace UI {
    class Menu {
    public:
        virtual ~Menu() {}
        virtual void drawMenu(sf::RenderWindow& window) = 0;
        virtual void moveUp() = 0;
        virtual void moveDown() = 0;
        virtual int getSelectedState() = 0;
        virtual void drawBackground(sf::RenderWindow& i_window) = 0;
    };

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Main Menu class
    class MainMenu : public Menu {
    public:
        MainMenu();
        void drawBackground(sf::RenderWindow& i_window) override;
        void drawMenu(sf::RenderWindow& window) override;
        void moveUp() override;
        void moveDown() override;
        int getSelectedState() override;

    private:
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

    // Play Menu class
    class PlayMenu : public Menu {
    public:
        PlayMenu();
        void drawBackground(sf::RenderWindow& i_window) override;
        void drawMenu(sf::RenderWindow& window) override;
        void moveUp() override;
        void moveDown() override;
        int getSelectedState() override;

    private:
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

    // Theme Menu class
    class ThemeMenu : public Menu {
    public:
        ThemeMenu();
        void drawBackground(sf::RenderWindow& i_window) override;
        void drawMenu(sf::RenderWindow& window) override;
        void moveUp() override;
        void moveDown() override;
        int getSelectedState() override;

    private:
        const short Width;
        const short Height;
        int SelectedMenu;
        std::string Themes[3];
        sf::Font menuFont;
        sf::Text MenuText[3];
        sf::RectangleShape MenuBox[3];

        sf::Texture background_texture;
        sf::Sprite background_sprite;
    };

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