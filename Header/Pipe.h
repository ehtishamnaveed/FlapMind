#ifndef PIPE_H
#define PIPE_H
#include "../Header/GameMode.h"

namespace Game {
	class Pipe {
	public:
		Pipe(short x, unsigned short y, GameModes GameType);
		void draw(sf::RenderWindow& i_window);
		void update();
		const bool isRemoveable() const;
		const short getXPosition() const ;
		const unsigned short getYPosition() const;
		const unsigned char getGapSize() const;
		const unsigned char getPipeSpeed() const;

	private:
		// bool direction;
		short X_Position;
		unsigned short Y_Position;
		static constexpr short OffScreenLimit = -50;
		// unsigned char y_MovementTimer;

		unsigned char GapSize;
		unsigned char PipeSpeed;

		// Variables for Easy gamemode
		static  constexpr unsigned char EasyGapSize = 120;
		static constexpr unsigned char EasyPipeSpeed = 2;

		// Variables for Hard gamemode
		static  constexpr unsigned char HardGapSize = 80;
		static constexpr unsigned char HardPipeSpeed = 4;

		// Variables for Crazy gamemode
		static  constexpr unsigned char CrazyGapSize = 100;
		static constexpr unsigned char CrazyPipeSpeed = 1;

		sf::Sprite pipe;
		sf::Texture texture;
	};
}

#endif