#include <SFML/Graphics.hpp>
#include "../Header/UI.h"

namespace UI {
	// Constructor Initilizes the Font and the Text on the window
	MainMenu::MainMenu(): Width(600), Height(600) {
		// Load the font
		menuFont.loadFromFile("Resources/Font/MenuFont.ttf");

		// Play 
		MenuText[0].setFont(menuFont);
		MenuText[0].setFillColor(sf::Color::White);
		MenuText[0].setString("Play");
		MenuText[0].setCharacterSize(30);
		MenuText[0].setPosition(Width/2-120,Height/2);

		// AI Playthrough
		MenuText[1].setFont(menuFont);
		MenuText[1].setFillColor(sf::Color::Black);
		MenuText[1].setString("AI Playthrough");
		MenuText[1].setCharacterSize(30);
		MenuText[1].setPosition(Width/2-120,Height/2+50);

		// Options
		MenuText[2].setFont(menuFont);
		MenuText[2].setFillColor(sf::Color::Black);
		MenuText[2].setString("Options");
		MenuText[2].setCharacterSize(30);
		MenuText[2].setPosition(Width/2-120,Height/2+100);

		MainMenuSelected = 0;
	}

	// Draw the Elements of Main Menu
	void MainMenu::drawMenu(sf::RenderWindow& i_window) {
		for(int iterator = 0 ; iterator < 3 ; ++iterator)
			i_window.draw(MenuText[iterator]);
	}

	int MainMenu::mainMenuPressed() {
		return MainMenuSelected;
	}

	// Navigate Up in Menu
	void MainMenu::moveUp() {
		MenuText[MainMenuSelected].setFillColor(sf::Color::Black);

	    MainMenuSelected = (MainMenuSelected - 1 + 3) % 3;

	    MenuText[MainMenuSelected].setFillColor(sf::Color::White);
	}

	// Navigate Down in Menu
	void MainMenu::moveDown() {
		MenuText[MainMenuSelected].setFillColor(sf::Color::Black);

	    MainMenuSelected = (MainMenuSelected + 1) % 3;

	    MenuText[MainMenuSelected].setFillColor(sf::Color::White);
	}
}
