#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // Include the Audio header
#include "../Header/UI.h"

namespace UI {
// MainMenu //
	// Constructor Initilizes the Font and the Text on the window
	MainMenu::MainMenu(): Width(600), Height(600), SelectedMenu(0) {
		// Load the font
		menuFont.loadFromFile("Resources/Font/MenuFont.ttf");

		for (int iterator = 0; iterator < 3; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 120, Height/2 + iterator * 50);
		}

		// Play
		MenuText[0].setString("Play");
		MenuText[0].setFillColor(sf::Color::White);

		// AI Playthrough
		MenuText[1].setString("AI Playthrough");
		MenuText[1].setFillColor(sf::Color::Black);

		// Theme
		MenuText[2].setString("Theme");
		MenuText[2].setFillColor(sf::Color::Black);
	}

	// Draw the Elements of Main Menu
	void MainMenu::drawMenu(sf::RenderWindow& i_window) {
		drawBackground(i_window);
		for(int iterator = 0 ; iterator < 3 ; ++iterator)
			i_window.draw(MenuText[iterator]);
	}

	// Navigate Up in Menu
	void MainMenu::moveUp() {
		MenuText[SelectedMenu].setFillColor(sf::Color::Black);

	    SelectedMenu = (SelectedMenu - 1 + 3) % 3;

	    MenuText[SelectedMenu].setFillColor(sf::Color::White);
	}

	// Navigate Down in Menu
	void MainMenu::moveDown() {
		MenuText[SelectedMenu].setFillColor(sf::Color::Black);

	    SelectedMenu = (SelectedMenu + 1) % 3;

	    MenuText[SelectedMenu].setFillColor(sf::Color::White);
	}

	// Return the index of Selected Menu
	int MainMenu::getSelectedState() {
		return SelectedMenu;
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
	PlayMenu::PlayMenu(): Width(600), Height(600), SelectedMenu(0) {
		// Load the font
		menuFont.loadFromFile("Resources/Font/MenuFont.ttf");

		for (int iterator = 0; iterator < 3; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 120, 180 + iterator * 80);
		}

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

	// Draw the Elements of Main Menu
	void PlayMenu::drawMenu(sf::RenderWindow& i_window) {
		drawBackground(i_window);
		for(int iterator = 0 ; iterator < 3 ; ++iterator)
			i_window.draw(MenuText[iterator]);
	}

	// Navigate Up in Menu
	void PlayMenu::moveUp() {
		MenuText[SelectedMenu].setFillColor(sf::Color::Black);

	    SelectedMenu = (SelectedMenu - 1 + 3) % 3;

	    MenuText[SelectedMenu].setFillColor(sf::Color::White);
	}

	// Navigate Down in Menu
	void PlayMenu::moveDown() {
		MenuText[SelectedMenu].setFillColor(sf::Color::Black);

	    SelectedMenu = (SelectedMenu + 1) % 3;

	    MenuText[SelectedMenu].setFillColor(sf::Color::White);
	}

	// Return the index of Selected Menu
	int PlayMenu::getSelectedState() {
		return SelectedMenu;
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
	ThemeMenu::ThemeMenu(): Width(600), Height(600), SelectedMenu(0) {
		// Initilizeing Themes array
		Themes[0] = "ClearSky";
		Themes[1] = "DarkNight";
		Themes[2] = "SunSet";

		// Load the font
		menuFont.loadFromFile("Resources/Font/MenuFont.ttf");

		for (int iterator = 0; iterator < 3; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 120, 180 + iterator * 80);
		}

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

	// Draw the Elements of Main Menu
	void ThemeMenu::drawMenu(sf::RenderWindow& i_window) {
		drawBackground(i_window);
		for(int iterator = 0 ; iterator < 3 ; ++iterator)
			i_window.draw(MenuText[iterator]);
	}

	// Navigate Up in Menu
	void ThemeMenu::moveUp() {
		MenuText[SelectedMenu].setFillColor(sf::Color::Black);

	    SelectedMenu = (SelectedMenu - 1 + 3) % 3;

	    MenuText[SelectedMenu].setFillColor(sf::Color::White);
	}

	// Navigate Down in Menu
	void ThemeMenu::moveDown() {
		MenuText[SelectedMenu].setFillColor(sf::Color::Black);

	    SelectedMenu = (SelectedMenu + 1) % 3;

	    MenuText[SelectedMenu].setFillColor(sf::Color::White);
	}

	// Return the index of Selected Menu
	int ThemeMenu::getSelectedState() {
		return SelectedMenu;
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



// Menu Manager class
    // Constructor initilizes the Window and sets its frame-rate limt
    MenuManager::MenuManager(): window(sf::VideoMode(Game::Screen::screenWidth, Game::Screen::screenHeight), "FlapMind") {
    	// Window FrameRateLimit
    	window.setFramerateLimit(60);

    	// Load Loading Screen FX
        FXsound.loadFromFile("Resources/SoundFX/Loading.wav");

        // Associate sound buffer with sound object
        LoadingFX.setBuffer(FXsound);
    }

    // Displays the Menu
	void MenuManager::displayMenu(UI::Menu*& currentMenu) {
		// Display the Project Group Logo
		sf::Texture texture;
    	texture.loadFromFile("Resources/Images/LoadingScreen.png");
    	sf::Sprite sprite(texture);
    	window.draw(sprite);
    	window.display();
    	// Play the Loading Screen Sound
		playLoadingFX();
		// Hold the Screen for 3 second
		std::this_thread::sleep_for(std::chrono::seconds(3));
    	window.clear();

    	playMainMenuMusic();

		bool keyPressed = false;  // Flag to track key press

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
            	if (event.type == sf::Event::Closed){
            		Game::saveConfiguration();
                    window.close();
            	}
            	else if (event.type == sf::Event::KeyPressed && !keyPressed) {
                	keyPressed = true;  // Set the flag to true to indicate key press
	                EventManager.processKeyPressed(event.key.code, currentMenu, *this);
	            }
	            else if (event.type == sf::Event::KeyReleased) {
	                keyPressed = false;  // Reset the flag on key release
	            }
	        }
            // Draws menu on window
            currentMenu->drawMenu(window);
            // Draws The window
            window.display();
            // Clear the window
            window.clear();
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
				break;

			// Theme
			case 2:
				// Change the Menu to ThemeMenu type
				delete currentMenu;
				currentMenu = new UI::ThemeMenu();
				break;
		}

    }

    // Play Menu Handler
    void MenuManager::handlePlayMenu(UI::Menu*& currentMenu) {
    	bool gameRestartState = true;
    	unsigned short* bestScore;
    	this->stopMainMenuMusic();

    	while (gameRestartState) {
    		GameController.resetGameState();
	    	switch (currentMenu->getSelectedState()) {
				// Easy
				case 0:
					bestScore = &Game::easymode_highscore;
					GameController.setGameMode(Game::GameModes::Easy);
					GameController.runGame(window);
					break;

				// Hard
				case 1:
					bestScore = &Game::hardmode_highscore;
					GameController.setGameMode(Game::GameModes::Hard);
					GameController.runGame(window);
					break;

				// Crazy
				case 2:
					bestScore = &Game::crazymode_highscore;
					GameController.setGameMode(Game::GameModes::Crazy);
					GameController.runGame(window);
					break;
			}

			// Game Over
			GameController.displayGameOverOverlay(window,bestScore);
			gameRestartState = EventManager.processGameOverState(window);
		}
    }

    // Theme Menu Handler
     void MenuManager::handleThemeMenu(UI::Menu*& currentMenu) {
    	switch (currentMenu->getSelectedState()) {
			// ClearSky Theme
			case 0:
				Game::theme_name = "ClearSky";
				delete currentMenu;
	            currentMenu = new UI::MainMenu();
				break;

			// DarkNight Theme
			case 1:
				Game::theme_name = "DarkNight";
				delete currentMenu;
	            currentMenu = new UI::MainMenu();
				break;

			// SunSet Theme
			case 2:
				Game::theme_name = "SunSet";
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

    void MenuManager::stopMainMenuMusic() {
    	LoadingFX.stop();
    }

// END OF NAMESPACE
}