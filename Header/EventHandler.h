#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <SFML/Audio.hpp>

namespace UI {
    class Menu; // Forward declaration
    class MenuManager;
}

namespace Game {
    class EventHandler {
    public:
        EventHandler();
        
        // Function to play a sound
        void playFX();
        void EnterFX();

        // Handles specific Key pressed Events only
        void processKeyPressed(const sf::Keyboard::Key& key, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler);

        // Handles Game Over state
        bool processGameOverState(sf::RenderWindow& i_window);

    private:
        // Hover Sound
        sf::SoundBuffer FXsound;
        sf::Sound MenuFX;

        sf::SoundBuffer EnterFXsound;
        sf::Sound Enter;
    };
}

#endif