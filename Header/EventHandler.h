#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

namespace UI {
    class Menu; // Forward declaration
    class MenuManager;
}

namespace Game {
    class EventHandler {
    public:
        // Handles specific Key pressed Events only
        void processKeyPressed(const sf::Keyboard::Key& key, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler);
        bool processGameOverState(sf::RenderWindow& i_window);
    };
}

#endif