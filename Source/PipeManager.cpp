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
		if (0 == GeneratorTimer) {
			GeneratorTimer = GeneratorDuration;
			Pipes.push_back(Pipe(Game::Screen::screenWidth, Y_Distribution(RandomEngine), GameType));
		}
		--GeneratorTimer;

		for (Pipe& curr_pipe : Pipes) {
			curr_pipe.update();
		}

		for (std::vector<Pipe>::iterator curr_pipe = Pipes.begin(); curr_pipe != Pipes.end(); curr_pipe++){
			// When the pipes go beyond the screen.
			if (curr_pipe->isRemoveable()){
				// We delete them.
				Pipes.erase(curr_pipe);
				break;
			}
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
			 	break;
		}
		Y_Distribution = std::uniform_int_distribution<unsigned short>(PipeIndent, Game::Screen::screenHeight - PipeIndent);
		GeneratorTimer = GeneratorDuration;
	}

	void PipeManager::setAISettings() {
		GameType = GameModes::Hard;
		PipeIndent = HardPipeIndent;
    	GeneratorDuration = HardGeneratorDuration;
	}

	const std::uniform_int_distribution<unsigned short>& PipeManager::getYDistribution() const {
		return Y_Distribution;
	}

	const unsigned char& PipeManager::getPipeIndent() const {
		return PipeIndent;
	}

}