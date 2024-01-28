#ifndef UI_H
#define UI_H

namespace UI {
    enum class MainMenuAction{
        Play,
        AI_Playthrough,
        Options,
    };


    class MainMenu {
    public:
        MainMenu();
        void drawMenu(sf::RenderWindow& i_window);
        void moveUp();
        void moveDown();
        int mainMenuPressed();

    private:
        short Width;
        short Height;
        int MainMenuSelected;
        sf::Font menuFont;
        sf::Text MenuText[3];
    };
}

#endif