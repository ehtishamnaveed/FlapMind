#include <SFML/Graphics.hpp>
#include "../Header/Pipe.h"
#include "../Header/Game.h"

namespace Game {
	// Constructor initilizes the Pipe's X and Y co-ordinates while loading the Pipe texture
	Pipe::Pipe(short x_origin, unsigned short y_origin, GameModes GameType): 
		PipeXPosition(x_origin), 
		PipeYPosition(y_origin) 
		// Body of Constructor
		{ texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/Pipe.png");
			switch (GameType) {
			 case GameModes::Easy:
			 	GapSize = EasyGapSize;
			 	PipeSpeed = EasyPipeSpeed;
			 	break;

            case GameModes::Hard:
            	GapSize = HardGapSize;
            	PipeSpeed = HardPipeSpeed;
			 	break;

            case GameModes::Crazy:
            	GapSize = CrazyGapSize;
            	PipeSpeed = CrazyPipeSpeed;
			 	break;
			}
		}

	// Sets the Tecture, while selecting specifc portion for Up-side and Down-side
	void Pipe::draw(sf::RenderWindow& i_window) {
		pipe.setTexture(texture);

		// Top Side Pipe
		pipe.setPosition(PipeXPosition, (PipeYPosition - Game::Screen::screenHeight));
		// Left, Top, Width, Height
		pipe.setTextureRect(sf::IntRect(50, 0, 50, Game::Screen::screenHeight));
		i_window.draw(pipe);

		//Using 1 sprite to draw 2 pipes.
		//OPTIMIZATION 100

		// Bottom Side Pipe
		pipe.setPosition(PipeXPosition, (PipeYPosition + GapSize));
		pipe.setTextureRect(sf::IntRect(0, 0, 50, Game::Screen::screenHeight));
		i_window.draw(pipe);
	}

	void Pipe::update() {
		PipeXPosition -= PipeSpeed;

		// if (pipeIndent == PipeYPosition)
		// {
		// 	direction = 1;
		// }
		// else if (PipeYPosition == 288 - 64 - pipeIndent)
		// {
		// 	direction = 0;
		// }
		
		// if (0 == y_MovementTimer)
		// {
		// 	y_MovementTimer = 1;

		// 	if (0 == direction)
		// 	{
		// 		PipeYPosition--;
		// 	}
		// 	else
		// 	{
		// 		PipeYPosition++;
		// 	}
		// }
		// else
		// {
		// 	y_MovementTimer--;
		// }
	}

	// Checks if the Pipe is beyond the Screen
	const bool Pipe::isRemoveable() const {
		return PipeXPosition <= OffScreenLimit;
	}

	const short Pipe::getXPosition() const {
		return PipeXPosition;
	}

	const unsigned short Pipe::getYPosition() const {
		return PipeYPosition;
	}

	const unsigned char Pipe::getGapSize() const {
		return GapSize;
	}
	
	const unsigned char Pipe::getPipeSpeed() const{
		return PipeSpeed;
	}

}