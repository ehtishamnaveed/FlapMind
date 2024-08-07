#include <SFML/Graphics.hpp>
#include "../Header/Pipe.h"
#include "../Header/Game.h"

namespace Game {
	// Constructor initilizes the Pipe's X and Y co-ordinates while loading the Pipe texture
	// And setting up the Setting of Pipes respect to GameMode type
	Pipe::Pipe(short x_origin, unsigned short y_origin, GameModes GameType): 
		PipeXPosition(x_origin), 
		PipeYPosition(y_origin), IsPipeMoving(false)
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
		pipe.setTextureRect(sf::IntRect(PipeWidth, 0, PipeWidth, Game::Screen::screenHeight));
		i_window.draw(pipe);

		//Using 1 sprite to draw 2 pipes.
		//OPTIMIZATION 100

		// Bottom Side Pipe
		pipe.setPosition(PipeXPosition, (PipeYPosition + GapSize));
		pipe.setTextureRect(sf::IntRect(0, 0, PipeWidth, Game::Screen::screenHeight));
		i_window.draw(pipe);
	}

	void Pipe::generateVerticalMovementDirection() {
		PipeMovementDirection = std::rand() % 2 == 0 ? VerticalMovement::UP : VerticalMovement::DOWN;
	}

	// Updates the Pipe X_position
	void Pipe::update() {
		PipeXPosition -= PipeSpeed;
	}

	// Make the Pipe Move Vertically Up and Down
	void Pipe::moveVertically() {
		// If the Pipe Movement Direction is Vertically Upwards
		if (PipeMovementDirection == VerticalMovement::UP) {
			// We move the pipes upwards
			--PipeYPosition;
			// PipeYPosition -= PipeSpeed;
		}
		// If the Pipe Movement Direction is Vertically Downwards
		else if (PipeMovementDirection == VerticalMovement::DOWN) {
			// We move the pipe downwards
			++PipeYPosition;
			// PipeYPosition += PipeSpeed;
		}

		// If pipe Y_Position has exceded TopScreenLimit
		if (PipeYPosition <= TopScreenLimit) {
			// Change the pipe movement direction to 'downwards'
			PipeMovementDirection = VerticalMovement::DOWN;
		}
		// If pipe Y_Position has exceded BottomScreenLimit
		else if (PipeYPosition >= BottomScreenLimit) {
			// Change the pipe movement direction to 'upwards'
			PipeMovementDirection = VerticalMovement::UP;
		}
	}

	void Pipe::setVerticalMovementLimits(unsigned char& PipeIndent) {
		TopScreenLimit = PipeIndent - GapSize + 110;
		BottomScreenLimit = Game::Screen::screenHeight - PipeIndent;
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

	const unsigned char Pipe::getPipeWidth() const{
		return PipeWidth;
	}
}