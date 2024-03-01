#include "../Header/NeuralNetwork.h"
#include <iostream> // Removeable

namespace NeuralNetwork {
	// Constrcutor
	AI::AI(): Game::Bird(), RandomEngine(std::random_device{}()), NodeDistribution(-1, std::nextafter(1, 2)) {}

	// Generate weights for edges
	void AI::generateWeights() {
	    // Set weights of edges from 'Input to Hidden' nodes
		for (size_t inputNode = 0; inputNode < input_nodes; ++inputNode) {
	        for (size_t hiddenNode = 0; hiddenNode < hidden_nodes; ++hiddenNode) {
	            // Generate a weight for each edge
				Weights.InputToHiddenWeights[inputNode][hiddenNode] = NodeDistribution(RandomEngine);
	            std::cerr << Weights.InputToHiddenWeights[inputNode][hiddenNode] << " ";
	        }
	    }

	    // Set weights of edges from 'Hidden to Output' nodes
		for (size_t hiddenNode = 0; hiddenNode < hidden_nodes; ++hiddenNode) {
	        for (size_t outputNode = 0; outputNode < output_nodes; ++outputNode) {
	            // Generate a weight for each edge
				Weights.HiddenToOutputWeights[hiddenNode][outputNode] = NodeDistribution(RandomEngine);
	            std::cerr << Weights.HiddenToOutputWeights[hiddenNode][outputNode] << " ";
	        }
	    }
	}


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
		generateWeights();
		// calculateDifference(Pipes);
		// updateBird();
		// drawBird(i_window);
	}
}