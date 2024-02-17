#include "../Header/NeuralNetwork.h"

namespace NeuralNetwork {
	void AI::calculateDifference(const std::vector<Game::Pipe>& Pipes) {
		unsigned char PipeGap = 0;
		for (const Game::Pipe& curr_pipe : Pipes) {
			if (BirdXPosition < curr_pipe.getXPosition() + BirdSize) {
				PipeGap = curr_pipe.getGapSize();
				PipeYPos = curr_pipe.getYPosition() + PipeGap - PipeGap / 2;
				break;
			}
		}
	}

	// ++++++++++++++
	bool AI::shouldFlap() {
		return (BirdYPosition > PipeYPos || BirdYPosition == PipeYPos);
	}

	// ++++++++++++++
	void AI::updateBird() {
		// Apply the Gravity to the Bird
		Vertical_Speed += Game::gravity;
		// And update its Y-axis Position
		BirdYPosition += Vertical_Speed;

		// If the Bird is Alive
		if (IsAlive) {
			if (0 <= Vertical_Speed && shouldFlap()) {
				// and Make the bird Falp
	        	Vertical_Speed = FlapSpeed;
				// Play the flap Sound
				// playFlapSound();
	    	}
		}

		// Check if the Bird reaches the Ground limit
		if (BirdYPosition >= Game::Screen::screenHeight - BirdGroundLimit) {
			Vertical_Speed = FlapSpeed;
		}
	}

	// ++++++++++++++
	void AI::playGame(sf::RenderWindow& i_window,const std::vector<Game::Pipe>& Pipes) {
		calculateDifference(Pipes);
		updateBird();
		drawBird(i_window);
	}
}