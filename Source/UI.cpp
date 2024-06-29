#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // Include the Audio header
#include "../Header/UI.h"

namespace UI {
// Menu //
	// Draw the Elements of Main Menu
	void Menu::drawMenu(sf::RenderWindow& i_window) {
		drawBackground(i_window);
		for(int iterator = 0 ; iterator < MenuSize ; ++iterator) {
			i_window.draw(MenuBox[iterator]); // Draw the box behind the text
			i_window.draw(MenuText[iterator]);
		}
	}

	// Navigate Up in Menu
	void Menu::moveUp() {
		MenuBox[SelectedMenu].setFillColor(sf::Color::Transparent);

		MenuText[SelectedMenu].setFillColor(sf::Color::Black);

	    SelectedMenu = (SelectedMenu - 1 + MenuSize) % MenuSize;

	    MenuText[SelectedMenu].setFillColor(sf::Color::White);

	    MenuBox[SelectedMenu].setFillColor(sf::Color::Black);
	}

	// Navigate Down in Menu
	void Menu::moveDown() {
		MenuBox[SelectedMenu].setFillColor(sf::Color::Transparent);

		MenuText[SelectedMenu].setFillColor(sf::Color::Black);

	    SelectedMenu = (SelectedMenu + 1) % MenuSize;

	    MenuText[SelectedMenu].setFillColor(sf::Color::White);

	    MenuBox[SelectedMenu].setFillColor(sf::Color::Black);
	}

	// Return the index of Selected Menu
	int Menu::getSelectedState() {
		return SelectedMenu;
	}



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// MainMenu //
	// Constructor Initilizes the Font and the Text on the window
	MainMenu::MainMenu(): Menu(4) {

		for (int iterator = 0; iterator < MenuSize; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 120, Height/2 + iterator * 50);

		    // Add box behind the text
	        MenuBox[iterator].setSize(sf::Vector2f(250, 40));
	        MenuBox[iterator].setFillColor(sf::Color::Transparent);
	        MenuBox[iterator].setPosition(Width / 2 - 125, Height / 2 + iterator * 50 - 5);
		}

		// Set the initial box to be selected
    	MenuBox[SelectedMenu].setFillColor(sf::Color::Black);

		// Play
		MenuText[0].setString("Play");
		MenuText[0].setFillColor(sf::Color::White);

		// AI Playthrough
		MenuText[1].setString("AI Play");
		MenuText[1].setFillColor(sf::Color::Black);

		// Theme
		MenuText[2].setString("Theme");
		MenuText[2].setFillColor(sf::Color::Black);

		// Controls
		MenuText[3].setString("Controls");
		MenuText[3].setFillColor(sf::Color::Black);
	}

	// Draw the Backgound for Main Menu
	void MainMenu::drawBackground(sf::RenderWindow& i_window) {
        background_texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/MainScreen.png");
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// PlayMenu //
	// Constructor Initilizes the Font and the Text on the window
	PlayMenu::PlayMenu(): Menu(3) {

		for (int iterator = 0; iterator < MenuSize; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 120, 180 + iterator * 80);

		    // Add box behind the text
	        MenuBox[iterator].setSize(sf::Vector2f(250, 40));
	        MenuBox[iterator].setFillColor(sf::Color::Transparent);
	        MenuBox[iterator].setPosition(Width / 2 - 120, 180 + iterator * 80);
		}

		// Set the initial box to be selected
    	MenuBox[SelectedMenu].setFillColor(sf::Color::Black);

		// Easy 
		MenuText[0].setFillColor(sf::Color::White);
		MenuText[0].setString("Easy");

		// Hard
		MenuText[1].setFillColor(sf::Color::Black);
		MenuText[1].setString("Hard");

		// Crazy
		MenuText[2].setFillColor(sf::Color::Black);
		MenuText[2].setString("Crazy");
	}

	// Draw the Backgound for Play Menu
	void PlayMenu::drawBackground(sf::RenderWindow& i_window) {
        background_texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/Background.png");
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// ThemeMenu //
	// Constructor Initilizes the Font and the Text on the window
	ThemeMenu::ThemeMenu(): Menu(3) {
		// Initilizeing Themes array
		Themes[0] = "ClearSky";
		Themes[1] = "DarkNight";
		Themes[2] = "SunSet";


		for (int iterator = 0; iterator < MenuSize; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 120, 180 + iterator * 80);

		    // Add box behind the text
	        MenuBox[iterator].setSize(sf::Vector2f(250, 40));
	        MenuBox[iterator].setFillColor(sf::Color::Transparent);
	        MenuBox[iterator].setPosition(Width / 2 - 120, 180 + iterator * 80);
		}

		// Set the initial box to be selected
    	MenuBox[SelectedMenu].setFillColor(sf::Color::Black);

		// ClearSky 
		MenuText[0].setFillColor(sf::Color::White);
		MenuText[0].setString("ClearSky");

		// Medium
		MenuText[1].setFillColor(sf::Color::Black);
		MenuText[1].setString("DarkNight");

		// SunSet
		MenuText[2].setFillColor(sf::Color::Black);
		MenuText[2].setString("SunSet");
	}

	// Draw the Backgound for Play Menu
	void ThemeMenu::drawBackground(sf::RenderWindow& i_window) {
        background_texture.loadFromFile("Resources/Theme/"+Themes[SelectedMenu]+"/Preview.png");
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// ControlsMenu //
	// Constructor Initilizes the Font and the Text on the window
	ControlsMenu::ControlsMenu(): Menu(3) {

		for (int iterator = 0; iterator < MenuSize; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 190, 180 + iterator * 80);

		    // Add box behind the text
	        MenuBox[iterator].setSize(sf::Vector2f(360, 40));
	        MenuBox[iterator].setFillColor(sf::Color::Transparent);
	        MenuBox[iterator].setPosition(Width/2 - 195, 180 + iterator * 80);
		}

		// Set the initial box to be selected
    	MenuBox[SelectedMenu].setFillColor(sf::Color::Black);

		// Easy 
		MenuText[0].setFillColor(sf::Color::White);
		MenuText[0].setString("Navigation Controls");

		// Hard
		MenuText[1].setFillColor(sf::Color::Black);
		MenuText[1].setString("Gameplay Controls");

		// Crazy
		MenuText[2].setFillColor(sf::Color::Black);
		MenuText[2].setString("Audio Controls");
	}

	// Draw the Backgound for Play Menu
	void ControlsMenu::drawBackground(sf::RenderWindow& i_window) {
        background_texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/Background.png");
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }

    // Shows Navigation Controls
    void ControlsMenu::showControls(sf::RenderWindow& i_window, std::string control_type, float x_pos, float y_pos) {
    	sf::Texture controls_texture;
        sf::Sprite controls;

        controls_texture.loadFromFile("Resources/Controls/"+control_type+".png");
        controls.setTexture(controls_texture);

        controls.setPosition(x_pos,y_pos);

        i_window.draw(controls);
        i_window.display();

        while (i_window.isOpen()) {
        	// Check for events
			sf::Event event;
	        while (i_window.waitEvent(event)) {
	        	// Check Event Type
	        	switch (event.type) {
	        		// Window closing event
	                case sf::Event::Closed:
	                    i_window.close();
	                    break;

	                // Key Pressed Events
	                case sf::Event::KeyPressed:
	                	// Check for the Keys
	                	switch(event.key.code) {
	                		case sf::Keyboard::Escape:
                            case sf::Keyboard::Backspace:
                            case sf::Keyboard::Enter:
                            	return;
                            	break;
	                	}
	                	break;
                }
			}
		}
    }



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// Menu Manager class
    // Constructor initilizes the Window and sets its frame-rate limt
    MenuManager::MenuManager(): window(sf::VideoMode(Game::Screen::screenWidth, Game::Screen::screenHeight), "FlapMind", sf::Style::Close) {
    	// Window FrameRateLimit
    	window.setFramerateLimit(60);

    	// Load Loading Screen FX
        FXsound.loadFromFile("Resources/SoundFX/Loading.wav");

        // Associate sound buffer with sound object
        LoadingFX.setBuffer(FXsound);
    }

    // Display the Project Group Logo
    void MenuManager::displayLogo() {
    	sf::Texture texture;
    	texture.loadFromFile("Resources/Images/LoadingScreen.png");
    	sf::Sprite sprite(texture);
    	window.draw(sprite);
    	window.display();

    	// Play the Loading Screen Sound
		playLoadingFX();

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

    	playMainMenuMusic();
    	
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
				// GameController.resetGameState();
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

    	// While game restart is true
    	while (game_restart_state) {
    		// Keep the last selected game mode
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
			}
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

    // Function to play Loading sound
    void MenuManager::playLoadingFX() {
    	if (!Game::mute)
        	LoadingFX.play();
    }

    // Play MainMenu Music
    void MenuManager::playMainMenuMusic() {
    	if (!Game::mute) {
    		// Load the MainMenu sound file
		    FXsound.loadFromFile("Resources/Bird is a Word.mp3");
		    LoadingFX.setBuffer(FXsound);

		    // Play the sound in a loop
		    LoadingFX.setLoop(true);
		    LoadingFX.play();
    	}
    }

    // Stops the Music
    void MenuManager::stopMainMenuMusic() {
    	LoadingFX.stop();
    }

// END OF NAMESPACE
}