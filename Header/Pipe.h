#ifndef PIPE_H
#define PIPE_H
#include "../Header/GameMode.h"

namespace Game {

	enum class VerticalMovement {
		UP,
		DOWN
	};

	class Pipe {
	public:
		// Constructor Initilizes the PipeGap and Speed Respective to The GameMode
		Pipe(short x, unsigned short y, GameModes GameType);
		// Draws The Pipe on Screen
		void draw(sf::RenderWindow& i_window);
		// Updates the Pipe's X_position
		void update();

		const bool isRemoveable() const; // Checks If the Pipe is removeable
		const short getXPosition() const; // Returns the X Position
		const unsigned short getYPosition() const; // Returns the Y Position
		const unsigned char getGapSize() const; // Returns the 'GapSize' for the Respective GameMode
		const unsigned char getPipeSpeed() const; // Returns the 'PipeSpeed' for the Respective GameMode
		const unsigned char getPipeWidth() const; // Returns PipeWidth

		// Generates the Movement Direction for the Pipe 
		void generateVerticalMovementDirection();
		// Sets the Movement Limit
		void setVerticalMovementLimits(unsigned char& PipeIndent);
		// Moves the Pipe Vertically Up and Down
		void moveVertically();

		bool haveMovement() { return IsPipeMoving; }
		void becomeMoveable() { IsPipeMoving = true; }

	private:
		bool IsPipeMoving;
		VerticalMovement PipeMovementDirection; // '0' means Up direction, '1' means Down direction

		unsigned short TopScreenLimit;
		unsigned short BottomScreenLimit;

		short PipeXPosition;
		unsigned short PipeYPosition;
		static constexpr short OffScreenLimit = -50; // Range of Pipe's X_positon to get removed
		static constexpr unsigned char PipeWidth = 50;

		unsigned char GapSize;
		unsigned char PipeSpeed;

		// Variables for Easy gamemode
		static constexpr unsigned char EasyGapSize = 130;
		static constexpr unsigned char EasyPipeSpeed = 4;

		// Variables for Hard gamemode
		static constexpr unsigned char HardGapSize = 90;
		static constexpr unsigned char HardPipeSpeed = 5;

		// Variables for Crazy gamemode
		static constexpr unsigned char CrazyGapSize = 100;
		static constexpr unsigned char CrazyPipeSpeed = 3;

		sf::Sprite pipe;
		sf::Texture texture;
	};
}

#endif