#include <SFML/Graphics.hpp>
#include "../Header/Bird.h"
#include "../Header/Game.h"

namespace Game {
	Bird::Bird(): Y_Position(20), X_Position(170), IsAlive(1) {} //(0.5f * (600 - 16)); }

	void Bird::drawBird(sf::RenderWindow& i_window) {
		texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/Birdy.png");
	    if (0 < Vertical_Speed) {
	    	// Left, Top, Width, Height
	    	bird.setTextureRect(sf::IntRect(0, 0, 50, BirdSize));
	    }
	    else {
	    	bird.setTextureRect(sf::IntRect(50, 0, 50, BirdSize));
	    }

	    bird.setTexture(texture);
	    bird.setPosition(X_Position, Y_Position);

	    i_window.draw(bird);
	}

	void Bird::updateBird() {
		// Apply the Gravity to the Bird
		Vertical_Speed += Game::gravity;
		// And update its Y-axis Position
		Y_Position += Vertical_Speed;

		// If the Bird is Alive
		if (IsAlive) {
			// And the Vertical speed is greater OR equal to 0, and the User presses the 'Up Arrow key'
			if (0 <= Vertical_Speed && sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
				// Then make the Bird Falp
	        	Vertical_Speed = FlapSpeed;
	    	}
		}

		// Check if the Bird reaches the Ground limit
		if (Y_Position >= Screen::screenHeight - GroundLimit) {
			// The Bird Dies
			IsAlive = 0;
			Vertical_Speed = 0;
			Y_Position = Screen::screenHeight - GroundLimit;
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