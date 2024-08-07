#ifndef UI_H
#define UI_H
#include "../Header/EventHandler.h"
#include "../Header/GameManager.h"
#include "../Header/Game.h"
#include <string>

namespace UI {
    class Menu {
    public:
        Menu(int size): Width(600), Height(600), SelectedMenu(0), MenuSize(size) {
            // Load the font
            menuFont.loadFromFile("Resources/Font/MenuFont.ttf");
            
            MenuText.resize(MenuSize);
            MenuBox.resize(MenuSize);
        }
        // Virtual destructor
        // To ensure destructor of the derived class is called correctly
        virtual ~Menu() {}
        void drawMenu(sf::RenderWindow& window);
        void moveUp();
        void moveDown();
        int getSelectedState();
        virtual void drawBackground(sf::RenderWindow& i_window) = 0;

        // Mouse support related functions
        void handleMouseMove(sf::Vector2i mousePosition);
        bool handleMouseClick(sf::Vector2i mousePosition);
        int getMenuItemAtPosition(sf::Vector2i mousePosition);
        bool isCursorOverItem(const sf::RectangleShape& item, sf::Vector2i mousePosition);

    protected:
        const short Width;
        const short Height;
        int SelectedMenu;
        int MenuSize;

        sf::Font menuFont;
        std::vector<sf::Text> MenuText;
        std::vector<sf::RectangleShape> MenuBox;

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
        std::string getTheme();

    private:
        std::string Themes[3];
    };

// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

    // Controls Menu class
    class ControlsMenu : public Menu {
    public:
        ControlsMenu();
        void drawBackground(sf::RenderWindow& i_window) override;
        void showControls(sf::RenderWindow& i_window, std::string control_type, float x_pos, float y_pos);
    };
}

#endif