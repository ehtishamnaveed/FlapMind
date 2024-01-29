#include <SFML/Graphics.hpp>
#include "../Header/UI.h"
#include <iostream>

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

		// Options
		MenuText[2].setString("Options");
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

	// Check the information about the Selected Menu
	void MainMenu::checkMenuInformation(UI::Menu*& currentMenu) {
	}

	// Return the index of Selected Menu
	int MainMenu::getSelectedState() {
		return SelectedMenu;
	}

	// Draw the Backgound for Main Menu
	void MainMenu::drawBackground(sf::RenderWindow& i_window) {
        background_texture.loadFromFile("Resources/Images/MainScreen.png");
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }



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

		// Medium
		MenuText[1].setFillColor(sf::Color::Black);
		MenuText[1].setString("Medium");

		// Hard
		MenuText[2].setFillColor(sf::Color::Black);
		MenuText[2].setString("Hard");
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

	// Check the information about the Selected Menu
	void PlayMenu::checkMenuInformation(UI::Menu*& currentMenu) {
	}

	// Return the index of Selected Menu
	int PlayMenu::getSelectedState() {
		return SelectedMenu;
	}

	// Draw the Backgound for Play Menu
	void PlayMenu::drawBackground(sf::RenderWindow& i_window) {
        background_texture.loadFromFile("Resources/Images/Background.png");
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// Menu Manager class
    // Constructor initilizes the Window and sets its frame-rate limt
    MenuManager::MenuManager(): window(sf::VideoMode(Game::Screen::screenWidth, Game::Screen::screenHeight), "Flappy Birds") {
    	// window.setFramerateLimit(30);
    }

    // Displays the Menu
	void MenuManager::displayMenu(UI::Menu*& currentMenu) {
        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
	            // Handles events of Game
	            EventManager.processEvent(window, event, currentMenu, *this);
	        }
	        // Clear the window
            window.clear();
            // Draws menu on window
            currentMenu->drawMenu(window);
            // Draws The window
            window.display();
        }
    }

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

			// Options
			case 2:
				break;
		}

    }

    void MenuManager::handlePlayMenu(UI::Menu*& currentMenu) {
    	switch (currentMenu->getSelectedState()) {
			// Easy
			case 0:
				currentMenu->drawBackground(window);
				GameController.runGame(window);
				break;

			// Medium
			case 1:
				break;

			// Hard
			case 2:
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

    	else
    		std::cerr << "Unknown menu type.";
    }

// END OF NAMESPACE
}