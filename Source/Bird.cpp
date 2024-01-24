#include <SFML/Graphics.hpp>
#include "../Header/Bird.h"
#include "../Header/Game.h"

namespace Game {
	Bird::Bird(): Y_Position(20), X_Position(170), IsAlive(1) { texture.loadFromFile("Resources/Images/Birdy.png"); } //(0.5f * (600 - 16)); }

	void Bird::drawBird(sf::RenderWindow& i_window) {
	    if (0 < Vertical_Speed) {
	    	// Left, Top, Width, Height
	    	bird.setTextureRect(sf::IntRect(0, 0, 51, 46));
	    }
	    else {
	    	bird.setTextureRect(sf::IntRect(51, 0, 51, 46));
	    }

	    bird.setTexture(texture);
	    bird.setPosition(X_Position, Y_Position);

	    i_window.draw(bird);
	}

	void Bird::updateBird() {
		Vertical_Speed += Game::gravity;
		Y_Position += Vertical_Speed;

		if (IsAlive) {
			if (0 <= Vertical_Speed && 1 == sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
	        	Vertical_Speed = FlapSpeed;
	    	}
		}

		if (Y_Position >= Screen::screenHeight - BirdSize) {
			IsAlive = 0;
			Vertical_Speed = 0;
			Y_Position = Screen::screenHeight - BirdSize;
		}
	}

	const unsigned char Bird::getBirdSize() const {
		return BirdSize;
	}

	const short Bird::getXPosition() const {
		return X_Position;
	}

	const float Bird::getYPosition() const {
		return Y_Position;
	}

	const char Bird::getFlapSpeed() const {
		return FlapSpeed;
	}

	void Bird::Dies() {
		IsAlive = 0;
	}

	bool Bird::isLiving() {
		return IsAlive;
	}

	void Bird::resetState() {
		Y_Position = 20;
	 	X_Position = 170;
	  	IsAlive = 1;
	}
}