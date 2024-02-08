#include <SFML/Graphics.hpp>
#include "../Header/EventHandler.h"
#include "../Header/Game.h"
#include "../Header/UI.h"


namespace Game {
	EventHandler::EventHandler() {
		// Load sound files into sound buffers
        FXsound.loadFromFile("Resources/SoundFX/MenuFX.mp3");

         // Associate sound buffers with sound objects
        MenuFX.setBuffer(FXsound);

        // Load sound files into sound buffers
        EnterFXsound.loadFromFile("Resources/SoundFX/EnterFX.mp3");

         // Associate sound buffers with sound objects
        Enter.setBuffer(EnterFXsound);
	}

	// Plays Menu hover sound
    void EventHandler::playFX() {
    	if (!Game::mute)
       		MenuFX.play();
    }

    // Plays Change Menu sound
    void EventHandler::EnterFX() {
    	if (!Game::mute)
        	Enter.play();
    }

    // Handles specific Key pressed Events only
    void EventHandler::processKeyPressed(const sf::Keyboard::Key& key, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler) {
     	switch (key) {
	        // Start the game when the Enter key is pressed
	        case sf::Keyboard::Enter:
	        	EnterFX();
	        	MenuHandler.handleMenuStateChange(currentMenu);
	            break;

	        case sf::Keyboard::Up:
	            playFX();
	            currentMenu->moveUp();
	            break;

	        case sf::Keyboard::Down:
	            playFX();
	            currentMenu->moveDown();
	            break;

	        case sf::Keyboard::Escape:
	          	delete currentMenu;
	            currentMenu = new UI::MainMenu();
	            break;

	        case sf::Keyboard::M:
	        	if (!Game::mute)
	          		Game::mute = true;
	          	else
	          		Game::mute = false;
	            break;

	        case sf::Keyboard::P:
	        	MenuHandler.playMainMenuMusic();
	         	break;

	        case sf::Keyboard::S:
	        	MenuHandler.stopMainMenuMusic();
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
	                break;
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