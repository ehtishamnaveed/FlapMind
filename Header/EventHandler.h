#ifndef EVENTHANDLER_H
#define EVENTHANDLER_H
#include <SFML/Audio.hpp>
#include "../Header/PipeManager.h"
#include "../Header/GameManager.h"

namespace UI {
    class Menu; // Forward declaration
    class MenuManager;
}

namespace Game {
    class EventHandler {
    public:
        EventHandler();
        // Function to play Menu 'FX' sound
        void playFX();
        void EnterFX();

        // Handles specific Key pressed Events only
        void processMenuKeyPressed(const sf::Keyboard::Key& key, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler);

        // Handles Game Over state
        bool processGameOverState(sf::RenderWindow& i_window);

        // Handles specific Key pressed Events for AI gameplay only
        void processAiGameplayKeyPressed(const sf::Keyboard::Key& key, PipeManager& PipeController, GameManager& GameController);

    private:
        // Hover Sound
        sf::SoundBuffer FXsound;
        sf::Sound MenuFX;

        sf::SoundBuffer EnterFXsound;
        sf::Sound Enter;
    };
}

#endif