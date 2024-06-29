#include <SFML/Graphics.hpp>
#include "../Header/EventHandler.h"
#include "../Header/Game.h"
#include "../Header/UI.h"


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
	        	MenuHandler.playMainMenuMusic();
	         	break;

	        // To 'Stop' the Menu Music
	        case sf::Keyboard::S:
	        	MenuHandler.stopMainMenuMusic();
	         	break;
	    }
    }

    // Handles Game Over state
    bool EventHandler::processGameOverState(sf::RenderWindow& i_window) {
    	bool state;
    	sf::Event event;
	        while (i_window.waitEvent(event)) {
	            if (event.type == sf::Event::Closed){
	                i_window.close();
	                state = false;
	                break;
	            }
	            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
	            	state = true;
	            	break;
	            }
	            else if (event.type == sf::Event::KeyPressed
	            	&& event.key.code == sf::Keyboard::Escape || event.key.code == sf::Keyboard::Backspace) {
	            	state = false;
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
	        	GameController.setGameMode(GameModes::Easy);
	            break;

	        // Change Game Mode to 'hard'
	        case sf::Keyboard::H:
	            GameController.setGameMode(GameModes::Hard);
	            break;

	        // Change Game Mode to 'crazy'
	        case sf::Keyboard::C:
	            GameController.setGameMode(GameModes::Crazy);
	            break;

	        // To go the 'Main Menu'
	        case sf::Keyboard::Escape:
	        case sf::Keyboard::Backspace:
	        	GameController.turnOffAiMode();
	            break;

	        // Move pipes vertically
	        case sf::Keyboard::M:
	        	if (!PipeController.movementIsEnabled())
	        		PipeController.allowPipesVerticalMovement();
	        	else
	        		PipeController.stopPipesVerticalMovement();
	         	break;
	    }
	}
}