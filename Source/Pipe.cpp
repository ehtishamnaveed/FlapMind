#include <SFML/Graphics.hpp>
#include "../Header/Pipe.h"
#include "../Header/Game.h"

namespace Game {
	// Constructor initilizes the Pipe's X and Y co-ordinates while loading the Pipe texture
	Pipe::Pipe(short x_origin, unsigned short y_origin): 
		X_Position(x_origin), 
		Y_Position(y_origin) {texture.loadFromFile("Resources/Images/P.png");}

	// Sets the Tecture, while selecting specifc portion for Up-side and Down-side
	void Pipe::draw(sf::RenderWindow& i_window) {
		pipe.setTexture(texture);

		// Top Side Pipe
		pipe.setPosition(X_Position, (Y_Position - Game::Screen::screenHeight));
		// Left, Top, Width, Height
		pipe.setTextureRect(sf::IntRect(50, 0, 50, Game::Screen::screenHeight));
		i_window.draw(pipe);

		//Using 1 sprite to draw 2 pipes.
		//OPTIMIZATION 100

		// Bottom Side Pipe
		pipe.setPosition(X_Position, (Y_Position + GapSize));
		pipe.setTextureRect(sf::IntRect(0, 0, 50, Game::Screen::screenHeight));
		i_window.draw(pipe);
	}

	void Pipe::update() {
		X_Position -= PipeSpeed;

		// if (pipeIndent == Y_Position)
		// {
		// 	direction = 1;
		// }
		// else if (Y_Position == 288 - 64 - pipeIndent)
		// {
		// 	direction = 0;
		// }
		
		// if (0 == y_MovementTimer)
		// {
		// 	y_MovementTimer = 1;

		// 	if (0 == direction)
		// 	{
		// 		Y_Position--;
		// 	}
		// 	else
		// 	{
		// 		Y_Position++;
		// 	}
		// }
		// else
		// {
		// 	y_MovementTimer--;
		// }
	}

	// Checks if the Pipe is beyond the Screen
	const bool Pipe::isRemoveable() const {
		return X_Position <= OffScreenLimit;
	}

	const short Pipe::getXPosition() const {
		return X_Position;
	}

	const unsigned short Pipe::getYPosition() const {
		return Y_Position;
	}

	const unsigned short Pipe::getGapSize() {
		return GapSize;
	}

	const unsigned short Pipe::getPipeSpeed() {
		return PipeSpeed;
	}
}