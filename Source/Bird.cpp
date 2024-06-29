#include <SFML/Graphics.hpp>
#include "../Header/Bird.h"
#include "../Header/Game.h"

namespace Game {
	Bird::Bird(): BirdYPosition(20), BirdXPosition(170), IsAlive(1) {
		// Load sound files into sound buffers
        FXsound.loadFromFile("Resources/SoundFX/FlapFX.mp3");

         // Associate sound buffers with sound objects
        FlapFX.setBuffer(FXsound);
	}

	void Bird::drawBird(sf::RenderWindow& i_window) {
		texture.loadFromFile("Resources/Theme/" + Game::theme_name + "/Birdy.png");
	    if (0 < BirdVerticalSpeed) {
	    	// Left, Top, Width, Height
	    	bird.setTextureRect(sf::IntRect(0, 0, 50, BirdSize));
	    }
	    else {
	    	bird.setTextureRect(sf::IntRect(50, 0, 50, BirdSize));
	    }

	    bird.setTexture(texture);
	    bird.setPosition(BirdXPosition, round(BirdYPosition));

	    i_window.draw(bird);
	}

	void Bird::updateBird() {
		// Apply the Gravity to the Bird
		BirdVerticalSpeed += Game::gravity;
		// And update its Y-axis Position
		BirdYPosition += BirdVerticalSpeed;

		// If the Bird is Alive
		if (IsAlive) {
			// And the Vertical speed is greater OR equal to 0
			// and the User presses the 'Up Arrow key' or 'Spacebar'
			if (0 <= BirdVerticalSpeed &&
				(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::Space))) {
				// and Make the bird Falp
	        	BirdVerticalSpeed = FlapSpeed;
				// Play the flap Sound
				playFlapSound();
	    	}
		}

		// Check if the Bird reaches the Ground limit
		if (BirdYPosition >= Screen::screenHeight - BirdGroundLimit) {
			// The Bird Dies
			IsAlive = 0;
			BirdVerticalSpeed = 0;
			BirdYPosition = Screen::screenHeight - BirdGroundLimit;
		}
	}

	const unsigned char Bird::getBirdSize() const {
		return BirdSize;
	}

	const short Bird::getXPosition() const {
		return BirdXPosition;
	}

	const float Bird::getYPosition() const {
		return BirdYPosition;
	}

	const char Bird::getFlapSpeed() const {
		return FlapSpeed;
	}

	void Bird::Dies() {
		IsAlive = false;
	}

	bool Bird::isAlive() {
		return IsAlive;
	}

	void Bird::resetState() {
		BirdVerticalSpeed = 0;
		BirdYPosition = 20;
	 	BirdXPosition = 170;
	  	IsAlive = true;
	}

	// Plays Flap Sound
    void Bird::playFlapSound() {
    	if (!Game::mute)
	   		FlapFX.play();
    }
}