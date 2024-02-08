#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H
#include <SFML/Audio.hpp>

namespace UI {
    class Menu; // Forward declaration
    class MenuManager;
}

namespace Game {
    class EventHandler {
    private:
        // Hover Sound
        sf::SoundBuffer FXsound;
        sf::Sound MenuFX;

        sf::SoundBuffer EnterFXsound;
        sf::Sound Enter;

    public:
        EventHandler();
        // Function to play a sound
        void playFX();
        void EnterFX();
        // Handles specific Key pressed Events only
        void processKeyPressed(const sf::Keyboard::Key& key, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler);
        bool processGameOverState(sf::RenderWindow& i_window);
    };
}

#endif