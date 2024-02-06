#include <SFML/Graphics.hpp>
#include "../Header/EventHandler.h"
#include "../Header/UI.h"

namespace Game {
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

    bool EventHandler::processGameOverState(sf::RenderWindow& i_window) {
    	bool state;
    	sf::Event event;
	        while (i_window.waitEvent(event)) {
	            if (event.type == sf::Event::Closed){
	                Game::saveConfiguration();
	                i_window.close();
	            }
	            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
	            	state = true;
	            	break;
	            }
	            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
	            	state = false;
	            	break;
	            }
	        }
        return state;
    }
}