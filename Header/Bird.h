#ifndef BIRD_H
#define BIRD_H

#include <SFML/Graphics.hpp>
#include "PipeManager.h"
#include <vector>

namespace Game {
	class Bird {
	public:
		Bird();
		void drawBird(sf::RenderWindow& i_window);
		void updateBird();

		const short getXPosition() const;
		const float getYPosition() const;
		const unsigned char getBirdSize() const;
		const char getFlapSpeed() const;

		void Dies();
		bool isLiving();
		void resetState();

	private:
		static constexpr char FlapSpeed = -4;
		static constexpr unsigned char BirdSize = 35;
		bool IsAlive;
		float Vertical_Speed;
		float Y_Position;
		short X_Position;

		sf::Sprite bird;
	    sf::Texture texture;
	};
}

#endif