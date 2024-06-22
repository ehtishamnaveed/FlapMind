#include <SFML/Graphics.hpp>
#include "../Header/PipeManager.h"
#include "../Header/Game.h"

namespace Game {	
	PipeManager::PipeManager(): RandomEngine(std::random_device{}()) {}

	// Draw Pipes on Screen
	void PipeManager::drawPipes(sf::RenderWindow& i_window) {
		for (Pipe& curr_pipe : Pipes){
			curr_pipe.draw(i_window);
		}
	}

	// Update Pipe positions and generate new location for Pipes
	void PipeManager::updatePipes() {
		if ( 0 == GeneratorTimer ) {
			GeneratorTimer = GeneratorDuration;
			Pipes.push_back(Pipe(Game::Screen::screenWidth, Y_Distribution(RandomEngine), GameType));
		}
		--GeneratorTimer;

		for ( Pipe& curr_pipe : Pipes ) {
			curr_pipe.update();

			// Check if pipe vertical movement is enabled
			if ( PipesCanMoveVertically ) {
				// If the current pipe doesn't have momenet
				if ( !curr_pipe.haveMovement() ) {
					// make it Moveable 
					curr_pipe.moveable();

					// Set the Top and Bottom movement limit for te pipe
					curr_pipe.setVerticalMovementLimits(PipeIndent);

					// Generate the Movement Direction for thr pipe
					curr_pipe.generateVerticalMovementDirection();
				}
				// Move Pipe Vertically
				curr_pipe.moveVertically();
			}
		}

		// This for loop is used to iterate and erase Removable pipes from Vector
		for (std::vector<Pipe>::iterator curr_pipe = Pipes.begin(); curr_pipe != Pipes.end(); ++curr_pipe){
			// When the pipes go beyond the screen.
			if (curr_pipe->isRemoveable()){
				// We delete them.
				Pipes.erase(curr_pipe);
				break;
			}
			// If the first Pipe is not removeable
			// that means other pipes are also on screen
			else break; // so we stop check for all pipes. OPTIMIZATION...
		}
	}

	const std::vector<Pipe>& PipeManager::getPipes() const {
		return Pipes;
	}

	void PipeManager::resetPipes() {
		GeneratorTimer = GeneratorDuration;
		Pipes.clear();
	}

	void PipeManager::setSettings(GameModes TypeOfMode) {
		GameType = TypeOfMode;
		PipesCanMoveVertically = false;

		switch (GameType) {
			case GameModes::Easy:
			 	PipeIndent = EasyPipeIndent;
			 	GeneratorDuration = EasyGeneratorDuration;
			 	break;

	        case GameModes::Hard:
	        	PipeIndent = HardPipeIndent;
	        	GeneratorDuration = HardGeneratorDuration;
			 	break;

	        case GameModes::Crazy:
	        	PipeIndent = CrazyPipeIndent;
	        	GeneratorDuration = CrazyGeneratorDuration;
	        	allowPipesVerticalMovement();
			 	break;
		}
		Y_Distribution = std::uniform_int_distribution<unsigned short>(PipeIndent, Game::Screen::screenHeight - PipeIndent);
		GeneratorTimer = GeneratorDuration;
	}

	const std::uniform_int_distribution<unsigned short>& PipeManager::getYDistribution() const {
		return Y_Distribution;
	}

	const unsigned char& PipeManager::getPipeIndent() const {
		return PipeIndent;
	}
}