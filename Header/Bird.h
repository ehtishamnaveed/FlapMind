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
		const int getYPosition() const;
		const unsigned char getBirdSize() const;
		const char getFlapSpeed() const;

		void Dies(); // Makes the Bird die
		bool isAlive(); // Return the Bird living state
		virtual void resetState(); // Resets the Bird state

	protected:
		static constexpr char FlapSpeed = -10;
		static constexpr unsigned char BirdSize = 42;
		static constexpr int BirdGroundLimit = 550;

		bool IsAlive;
		int BirdVerticalSpeed;
		short BirdXPosition;
		int BirdYPosition;

		sf::Sprite bird;
	    sf::Texture texture;

	    // Flap Sound
        sf::SoundBuffer FXsound;
        sf::Sound FlapFX;
	};
}

#endif