#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include "../Header/PipeManager.h"
#include <SFML/Audio.hpp>
#include <vector>

namespace Game {
	class Bird {
	public:
		Bird();
		// Plays Flap Sound
		void playFlapSound();

		void drawBird(sf::RenderWindow& i_window);
		virtual void updateBird();

		const short getXPosition() const;
		const float getYPosition() const;
		const unsigned char getBirdSize() const;
		const char getFlapSpeed() const;

		void Dies(); // Makes the Bird die
		bool isAlive(); // Return the Bird living state
		void resetState(); // Resets the Bird state

	protected:
		static constexpr char FlapSpeed = -9;
		static constexpr unsigned char BirdSize = 42;
		static constexpr char BirdGroundLimit = 35;

		bool IsAlive;
		float BirdVerticalSpeed;
		short BirdXPosition;
		float BirdYPosition;

		sf::Sprite bird;
	    sf::Texture texture;

	    // Flap Sound
        sf::SoundBuffer FXsound;
        sf::Sound FlapFX;
	};
}

#endif