#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // Include the Audio header
#include "../Header/UI.h"

namespace UI {
// Menu //
	// Draw the Elements of Main Menu
	void Menu::drawMenu(sf::RenderWindow& i_window) {
		drawBackground(i_window);
		for(size_t iterator = 0 ; iterator < MenuSize ; ++iterator) {
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

	// Function to handle mouse movement over menu items
	void Menu::handleMouseMove(sf::Vector2i mousePosition) {
		// Check which menu item the mouse is hovering over
	    int hoveredItem = getMenuItemAtPosition(mousePosition);
	    if (hoveredItem != -1) {
	    	// First Reset the previously selected item's appearance
	    	MenuBox[SelectedMenu].setFillColor(sf::Color::Transparent);
			MenuText[SelectedMenu].setFillColor(sf::Color::Black);

			// Update the selected item
	        SelectedMenu = hoveredItem;

	        // Then Apply hover effect to the newly selected item
	        MenuText[SelectedMenu].setFillColor(sf::Color::White);
	    	MenuBox[SelectedMenu].setFillColor(sf::Color::Black);
	    }
	}

	// Function to handle mouse clicks on menu items
	bool Menu::handleMouseClick(sf::Vector2i mousePosition) {
		// Check which menu item was clicked
	    int clickedItem = getMenuItemAtPosition(mousePosition);
	    if (clickedItem != -1) {
	        SelectedMenu = clickedItem;
	        return true; // Indicates a valid menu item was clicked
	    }
	    return false;  // Indicates no menu item was clicked
	}

	// Function to determine which menu item is at a given position
	int Menu::getMenuItemAtPosition(sf::Vector2i mousePosition) {
		// Iterate through all menu items
	    for (size_t itemIndex = 0; itemIndex < MenuSize; ++itemIndex) {
	    	// Check if the mouse is over the current item
	        if (isCursorOverItem(MenuBox[itemIndex], mousePosition)) {
	            return itemIndex;
	        }
	    }
	    return -1; // Indicates cursor is not over any menu item
	}

	// Function to check if the cursor is over a specific menu item
	bool Menu::isCursorOverItem(const sf::RectangleShape& item, sf::Vector2i mousePosition) {
		// Check if the mouse position is within the bounds of the menu item
	    return item.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	}



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// MainMenu //
	// Constructor Initilizes the Font and the Text on the window
	MainMenu::MainMenu(): Menu(4) {

		for (size_t iterator = 0; iterator < MenuSize; ++iterator) {
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
        if (!background_texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/MainScreen.png")) {
        	Game::theme_name = "ClearSky";
        	background_texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/MainScreen.png");
        }
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }



// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++



// PlayMenu //
	// Constructor Initilizes the Font and the Text on the window
	PlayMenu::PlayMenu(): Menu(3) {

		for (size_t iterator = 0; iterator < MenuSize; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 120, 180 + iterator * 80);

		    // Add box behind the text
	        MenuBox[iterator].setSize(sf::Vector2f(250, 40));
	        MenuBox[iterator].setFillColor(sf::Color::Transparent);
	        MenuBox[iterator].setPosition(Width / 2 - 125, 180 + iterator * 80);
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


		for (size_t iterator = 0; iterator < MenuSize; ++iterator) {
			MenuText[iterator].setFont(menuFont);
			MenuText[iterator].setCharacterSize(30);
		    MenuText[iterator].setPosition(Width/2 - 120, 180 + iterator * 80);

		    // Add box behind the text
	        MenuBox[iterator].setSize(sf::Vector2f(250, 40));
	        MenuBox[iterator].setFillColor(sf::Color::Transparent);
	        MenuBox[iterator].setPosition(Width / 2 - 125, 180 + iterator * 80);
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

		for (size_t iterator = 0; iterator < MenuSize; ++iterator) {
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
	                    return;

	                // Key Pressed Events
	                case sf::Event::KeyPressed:
	                	// Check for the Keys
	                	switch(event.key.code) {
	                		case sf::Keyboard::Escape:
                            case sf::Keyboard::Backspace:
                            case sf::Keyboard::Enter:
                            	return;
	                	}
	                	break;
                }
			}
		}
    }
}