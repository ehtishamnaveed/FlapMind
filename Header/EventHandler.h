#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

namespace UI {
    class Menu; // Forward declaration
    class MenuManager;
}

namespace Game {
    class EventHandler {
    public:
        // Processes What kind of Event is it
        void processEvent(sf::RenderWindow& window, const sf::Event& event, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler);
        // Handles specific Key pressed Events only
        void processKeyPressed(const sf::Keyboard::Key& key, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler);
    };
}

#endif