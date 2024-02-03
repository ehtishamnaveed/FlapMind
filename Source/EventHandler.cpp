#include <SFML/Graphics.hpp>
#include "../Header/EventHandler.h"
#include "../Header/UI.h"

namespace Game {
	// Processes What kind of Event is it
	// void EventHandler::processEvent(sf::RenderWindow& window, const sf::Event& event, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler) {
	// 	 switch (event.type) {
    //         // Close the window if the close button is pressed
    //         case sf::Event::Closed:
    //         	delete currentMenu;
    //             window.close();
    //             break;

    //         // Handle key presses
    //         case sf::Event::KeyPressed:
    //             processKeyPressed(event.key.code, currentMenu, MenuHandler);
    //             break;
    //     }
    // }

    // Handles specific Key pressed Events only
    void EventHandler::processKeyPressed(const sf::Keyboard::Key& key, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler) {
     	switch (key) {
	        // Start the game when the Enter key is pressed
	        case sf::Keyboard::Enter:
	        	MenuHandler.handleMenuStateChange(currentMenu);
	            break;

	        case sf::Keyboard::Up:
	            currentMenu->moveUp();
	            break;

	        case sf::Keyboard::Down:
	            currentMenu->moveDown();
	            break;

	          case sf::Keyboard::Escape:
	          	delete currentMenu;
	            currentMenu = new UI::MainMenu();
	            break;
	    }
    }
}