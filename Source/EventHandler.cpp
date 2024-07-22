#include <SFML/Graphics.hpp>
#include "../Header/EventHandler.h"
#include "../Header/Game.h"
#include "../Header/UI.h"
#include "../Header/MenuManager.h"

namespace Game {
	EventHandler::EventHandler() {
		// Load sound file into sound buffer
        FXsound.loadFromFile("Resources/SoundFX/MenuFX.mp3");

         // Associate sound buffer with sound object
        MenuFX.setBuffer(FXsound);

        // Load sound file into sound buffer
        EnterFXsound.loadFromFile("Resources/SoundFX/EnterFX.mp3");

         // Associate sound buffer with sound object
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
    void EventHandler::processMenuKeyPressed(const sf::Keyboard::Key& key, UI::Menu*& currentMenu, UI::MenuManager& MenuHandler) {
     	switch (key) {
	        // To go into the 'Next Menu'
	        case sf::Keyboard::Enter:
	        	EnterFX();
	        	MenuHandler.handleMenuStateChange(currentMenu);
	            break;

	        // To go 'Up' in the Menu
	        case sf::Keyboard::Up:
	            playFX();
	            currentMenu->moveUp();
	            break;

	        // To go 'Down' in the Menu
	        case sf::Keyboard::Down:
	            playFX();
	            currentMenu->moveDown();
	            break;

	        // To go the 'Main Menu'
	        case sf::Keyboard::Escape:
	        case sf::Keyboard::Backspace:
	        	playFX();
	          	delete currentMenu;
	            currentMenu = new UI::MainMenu();
	            break;

	        // To 'Mute' the Sound fx
	        case sf::Keyboard::M:
	        	// If the Game is not already mute
	        	if (!Game::mute)
	        		// Then Mute the game
	          		Game::mute = true;
	          	else
	          		// Else Unmute the Game
	          		Game::mute = false;
	            break;

	        // To 'Play' the Menu Music
	        case sf::Keyboard::P:
	        	// If the Game is not already mute
	        	if (!Game::pause) {
	        		// Then Mute the game
	          		Game::pause = true;
	          		MenuHandler.stopMainMenuMusic();
	          	}
	          	else {
	          		// Else Unmute the Game
	          		Game::pause = false;
	          		MenuHandler.playMainMenuMusic();
	          	}
	         	break;
	    }
    }

    // Handles Game Over state
    bool EventHandler::processGameOverState(sf::RenderWindow& i_window) {
    	bool state = false;
    	sf::Event event;
	        while (i_window.waitEvent(event)) {
	            if (event.type == sf::Event::Closed){
	                i_window.close();
	                break;
	            }
	            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
	            	state = true;
	            	break;
	            }
	            else if (event.type == sf::Event::KeyPressed
	            	&& event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Backspace) {
	            	playFX();
	            	break;
	            }
	        }
        return state;
    }

    // Handles specific Key pressed Events for AI Gameplay only
    void EventHandler::processAiGameplayKeyPressed(const sf::Keyboard::Key& key, PipeManager& PipeController, GameManager& GameController) {
     	switch (key) {
	        // Change Game Mode to 'easy'
	        case sf::Keyboard::E:
	        	playFX();
	        	GameController.setGameMode(GameModes::Easy);
	            break;

	        // Change Game Mode to 'hard'
	        case sf::Keyboard::H:
	        	playFX();
	            GameController.setGameMode(GameModes::Hard);
	            break;

	        // Change Game Mode to 'crazy'
	        case sf::Keyboard::C:
	        	playFX();
	            GameController.setGameMode(GameModes::Crazy);
	            break;

	        // To go the 'Main Menu'
	        case sf::Keyboard::Escape:
	        case sf::Keyboard::Backspace:
	        	playFX();
	        	GameController.turnOffAiMode();
	            break;

	        // Move pipes vertically
	        case sf::Keyboard::M:
	        	playFX();
	        	if (!PipeController.movementIsEnabled())
	        		PipeController.allowPipesVerticalMovement();
	        	else
	        		PipeController.stopPipesVerticalMovement();
	         	break;
	    }
	}

	// Handles Mouse
	void EventHandler::processMouseClick(UI::Menu*& currentMenu, UI::MenuManager& MenuHandler) {
	    EnterFX();
	    MenuHandler.handleMenuStateChange(currentMenu);
	}
}