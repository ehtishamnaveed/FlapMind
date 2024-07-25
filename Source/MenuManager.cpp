#include <SFML/Graphics.hpp>
#include "../Header/MenuManager.h"

namespace UI {
	// Menu Manager class
    // Constructor initilizes the Window and sets its frame-rate limt
    MenuManager::MenuManager(): window(sf::VideoMode(Game::Screen::screenWidth, Game::Screen::screenHeight), "FlapMind", sf::Style::Close) {
    	// Window FrameRateLimit
    	window.setFramerateLimit(60);

    	mainMenuMusic.openFromFile("Resources/Bird is a Word.mp3");
    	mainMenuMusic.setLoop(true);
    }

    // Display the Project Group Logo
    void MenuManager::displayLogo() {
    	sf::Image icon;
    	icon.loadFromFile("Resources/Images/winlogo.png");
    	window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    	sf::Texture texture;
    	texture.loadFromFile("Resources/Images/LoadingScreen.png");
    	sf::Sprite sprite(texture);
    	window.draw(sprite);
    	window.display();

    	// Loading Screen Sound
        sf::SoundBuffer FXsound;
        sf::Sound LoadingFX;
    	// Load Loading Screen FX
        FXsound.loadFromFile("Resources/SoundFX/Loading.wav");
        // Associate sound buffer with sound object
        LoadingFX.setBuffer(FXsound);
    	// Play the Loading Screen Sound
		if (!Game::mute)
        	LoadingFX.play();

		// Hold the Screen for 3 seconds for the Logo to stay
	    sf::Clock clock;
	    while (clock.getElapsedTime().asSeconds() < 3.f) {
	        // Keep the main thread responsive by processing events
	        sf::Event event;
	        while (window.pollEvent(event)) {
	            if (event.type == sf::Event::Closed)
	                window.close();
	        }
	    }
    }

    // Displays the Menu
	void MenuManager::displayMenu(UI::Menu*& currentMenu) {
		displayLogo();
    	
    	// Seed for rand()
    	srand(static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count()));

        while (window.isOpen()) {

            sf::Event event;
            while (window.pollEvent(event)) {

            	if (event.type == sf::Event::Closed){
            		window.close();
            	}

            	// Process Menu Events
            	else if (event.type == sf::Event::KeyPressed) {
            		// Process menu key events
	                EventManager.processMenuKeyPressed(event.key.code, currentMenu, *this);
	            }

	            // Mouse event process
	            else if (event.type == sf::Event::MouseMoved) {
	            	// Handle mouse movement over menu items
	                currentMenu->handleMouseMove(sf::Mouse::getPosition(window));
	            }

	            // Mouse clicK even process
	            else if (event.type == sf::Event::MouseButtonPressed) {
	            	// If 'Left' Mouse button is pressed
	                if (event.mouseButton.button == sf::Mouse::Left) {
	                	  // Check if a menu item was clicked
	                    if (currentMenu->handleMouseClick(sf::Mouse::getPosition(window))) {
	                    	// Process the click event
	                        EventManager.processMouseClick(currentMenu, *this);
	                    }
	                }
	            }
	        }
	        // Clear the window
            window.clear();
            // Draws menu on window
            currentMenu->drawMenu(window);
            // Draws The window
            window.display();
        }
    }

    // Main Menu Handler
    void MenuManager::handleMainMenu(UI::Menu*& currentMenu) {
    	switch (currentMenu->getSelectedState()) {
			// Play 
			case 0:
				// Change the Menu to PlayMenu type
				delete currentMenu;
				currentMenu = new UI::PlayMenu();
				break;

			// AI PlayThrough
			case 1:
				GameController.setGameMode(Game::GameModes::Easy);
				GameController.runAiGameplay(window);
				// After the AIGameplay, we return to Main Menu
				delete currentMenu;
				currentMenu = new UI::MainMenu();
				break;

			// Theme
			case 2:
				// Change the Menu to ThemeMenu type
				delete currentMenu;
				currentMenu = new UI::ThemeMenu();
				break;

			// Controls
			case 3:
				delete currentMenu;
				currentMenu = new UI::ControlsMenu();
				break;
		}
    }

    // Play Menu Handler
    void MenuManager::handlePlayMenu(UI::Menu*& currentMenu) {
    	bool game_restart_state = true;
    	unsigned short* bestScore;
    	stopMainMenuMusic();

		// Select the Gamemode and its respective Highscore too
    	switch (currentMenu->getSelectedState()) {
			// Easy
			case 0:
				bestScore = &Game::easymode_highscore;
				GameController.setGameMode(Game::GameModes::Easy);
				break;

			// Hard
			case 1:
				bestScore = &Game::hardmode_highscore;
				GameController.setGameMode(Game::GameModes::Hard);
				break;

			// Crazy
			case 2:
				bestScore = &Game::crazymode_highscore;
				GameController.setGameMode(Game::GameModes::Crazy);
				break;

			// Back to Main Menu
			case 3:
				delete currentMenu;
    			currentMenu = new UI::MainMenu();
				return;
		}

		// While game restart is true
    	while (game_restart_state) {
    		GameController.waitForStart(window);
			// Get into the Playthrough
			GameController.runGame(window);

			// Display Game Over overlay with highscore info
			GameController.displayGameOverOverlay(window,bestScore);
			// Check if user wants to restart 
			game_restart_state = EventManager.processGameOverState(window);

			// reset the game state
			GameController.resetGameState();
		}
    }

    // Theme Menu Handler
    void MenuManager::handleThemeMenu(UI::Menu*& currentMenu) {
    	switch (currentMenu->getSelectedState()) {
			// ClearSky Theme
			case 0:
				Game::theme_name = "ClearSky";
				break;

			// DarkNight Theme
			case 1:
				Game::theme_name = "DarkNight";
				break;

			// SunSet Theme
			case 2:
				Game::theme_name = "SunSet";
				break;

			// Back to Main Menu
			case 3:
				break;
		}
		delete currentMenu;
        currentMenu = new UI::MainMenu();
    }

    // Controls Menu Handler
    void MenuManager::handleControlsMenu(UI::Menu*& currentMenu) {
    	currentMenu->drawBackground(window);
    	UI::ControlsMenu* controls;
    	controls = dynamic_cast<ControlsMenu*>(currentMenu);

    	switch (currentMenu->getSelectedState()) {
    		// Menu Navigation Controls
    		case 0:
    			controls->showControls(window,"MenuControls",50.0f,150.0f);
    			break;

    		// Gameplay Controls
    		case 1:
    			controls->showControls(window,"GameplayControls",50.0f,120.0f);
    			break;

    		// Audio Controls
    		case 2:
    			controls->showControls(window,"AudioControls",50.0f,180.0f);
    			break;

    		// Back to Main Menu
			case 3:
				delete currentMenu;
        		currentMenu = new UI::MainMenu();
				break;
		}
    }

    void MenuManager::handleMenuStateChange(UI::Menu*& currentMenu) {
    	if (typeid(*currentMenu) == typeid(MainMenu)) {
	        handleMainMenu(currentMenu);
	    } 
	    else if (typeid(*currentMenu) == typeid(PlayMenu)) {
	        handlePlayMenu(currentMenu);
    	}
    	else if (typeid(*currentMenu) == typeid(ThemeMenu)) {
	        handleThemeMenu(currentMenu);
    	}
    	else if (typeid(*currentMenu) == typeid(ControlsMenu)) {
	        handleControlsMenu(currentMenu);
    	}
    }

    // Play MainMenu Music
    void MenuManager::playMainMenuMusic() {
	    mainMenuMusic.play();
    }

    // Stops the Music
    void MenuManager::stopMainMenuMusic() {
    	mainMenuMusic.stop();
    }

// END OF NAMESPACE
}