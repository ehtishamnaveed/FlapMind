#include "../Header/NeuralNetwork.h"
// #include<iostream>
namespace NeuralNetwork {
	// Constrcutor
	AI::AI(): Game::Bird(), FitnessScore(0),
			  RandomEngine(std::random_device{}()), 
			  NodeDistribution(-1, 1),
			  MutationDistribution(0, 99)
			  { BirdYPosition = 300; }

	// Generates random weights for edges
	void AI::generateEdgeWeights() {
	    // Generate weights from 'Input to Hidden' nodes
		// Loop through each 'Input Layer node'
		for (size_t inputNode = 0; inputNode < input_nodes; ++inputNode) {
	        // Connect each 'Input Layer node' to every 'Hidden layer Node'
			for (size_t hiddenNode = 0; hiddenNode < hidden_nodes; ++hiddenNode) {
	            // Generate a random weight for each edge
				Weights.InputToHiddenWeights[inputNode][hiddenNode] = NodeDistribution(RandomEngine);
	        }	
	    }

	    // Generate weights from 'Hidden to Output' nodes
		// Loop through each 'Hidden Layer node'
		for (size_t hiddenNode = 0; hiddenNode < hidden_nodes; ++hiddenNode) {
	        // Connect each 'Hidden Layer node' to the 'Output layer Node'
			for (size_t outputNode = 0; outputNode < output_nodes; ++outputNode) {
	            // Generate a random weight for each edge
				Weights.HiddenToOutputWeights[hiddenNode][outputNode] = NodeDistribution(RandomEngine);
 	        }
	    }
	}


	bool AI::activationFunction() {
		// First input node value is the birdVee
		Layers.InputLayer[0] = BirdVerticalSpeed;
		Layers.InputLayer[1] = BirdNPipeDifference;

		feedforwardToHiddenLayer();
		feedforwardToOutputLayer();
		
		return 0 <= Layers.OutputLayer[0];
	}


	void AI::feedforwardToHiddenLayer() {
		// hiddenIdx: Index of the current hidden layer node being computed.
		// inputIdx: Index of the current input layer node being used in the weighted sum calculation.

		// Compute the dot product of input nodes and input-to-hidden weights and add with the respective Hidden Node
	    for (size_t hiddenIdx = 0; hiddenIdx < hidden_nodes; ++hiddenIdx) {
	        Layers.HiddenLayer[hiddenIdx ] = 0.0f; // Initialize hidden node to 0.0f

	        for (size_t inputIdx = 0; inputIdx < input_nodes; ++inputIdx) {
	            Layers.HiddenLayer[hiddenIdx] += Layers.InputLayer[inputIdx] * Weights.InputToHiddenWeights[inputIdx][hiddenIdx];
	        }
	    	// +++++ Hyberbolic Tangent 
	        	Layers.HiddenLayer[hiddenIdx] = std::tanh(Layers.HiddenLayer[hiddenIdx]);

	        // if (0 >= Layers.HiddenLayer[hiddenIdx]) {
	        // 	Layers.HiddenLayer[hiddenIdx] = std::pow(2.0f, static_cast<float>(Layers.HiddenLayer[hiddenIdx])) - 1.0f;
	        // }
	        // else {
	        // 	Layers.HiddenLayer[hiddenIdx] = 1.0f - std::pow(2.0f, static_cast<float>(Layers.HiddenLayer[hiddenIdx]));
	        // }
        }
	}


	void AI::feedforwardToOutputLayer() {
		// hiddenIdx: Index of the current hidden layer node being computed.

		// Initialize output layer node to 0
	    Layers.OutputLayer[0] = 0.0f;

	    // Compute the dot product of hidden nodes and hidden-to-output weights and add with Output Node
	    for (size_t hiddenIdx = 0; hiddenIdx < hidden_nodes; ++hiddenIdx) {
	        Layers.OutputLayer[0] += Layers.HiddenLayer[hiddenIdx] * Weights.HiddenToOutputWeights[hiddenIdx][0];
	    }
	    // +++++ Hyberbolic Tangent
	    	Layers.OutputLayer[0] = std::tanh(Layers.OutputLayer[0]);

	    // if (0 >= Layers.HiddenLayer[0]) {
        // 	Layers.OutputLayer[0] = std::pow(2.0f, static_cast<float>(Layers.OutputLayer[0])) - 1.0f;
        // }
        // else {
        // 	Layers.OutputLayer[0] = 1.0f - std::pow(2.0f, static_cast<float>(Layers.OutputLayer[0]));
        // }
	}


	void AI::calculateDifference(const std::vector<Game::Pipe>& Pipes) {
		for (const Game::Pipe& curr_pipe : Pipes) {
			if (BirdXPosition < curr_pipe.getXPosition() + BirdSize) {
				BirdNPipeDifference = curr_pipe.getYPosition() + curr_pipe.getGapSize()  - BirdSize - BirdYPosition;
				break;
			}
		}
	}

	// ++++++++++++++
	bool AI::shouldFlap() {
		return activationFunction();
	}

	// ++++++++++++++
	void AI::updateBird() {
		// Apply the Gravity to the Bird
		BirdVerticalSpeed += Game::gravity;
		// And update its Y-axis Position
		BirdYPosition += BirdVerticalSpeed;

		// If the Bird is Alive
		if (IsAlive) {
			// Check if the Bird reaches the Ground limit
			if (BirdYPosition >= Game::Screen::screenHeight - BirdGroundLimit) {
				BirdVerticalSpeed = FlapSpeed;
			}

			if (0 <= BirdVerticalSpeed && shouldFlap()) {
				// and Make the bird Falp
	        	BirdVerticalSpeed = FlapSpeed;
				// Play the flap Sound
				// playFlapSound();
	    	}
	    	updateFitnessScore();
		}
		else {
			if (BirdYPosition >= (Game::Screen::screenHeight - BirdGroundLimit)) {
				if (BirdXPosition >= -50) {
					BirdYPosition = Game::Screen::screenHeight - BirdGroundLimit;
					BirdVerticalSpeed = 0;
					BirdXPosition--;
				}
			}
		}
	}

	void AI::updateFitnessScore() {
		FitnessScore++;
	}

	// ++++++++++++++
	void AI::playGame(sf::RenderWindow& i_window,const std::vector<Game::Pipe>& Pipes) {
		calculateDifference(Pipes);
		updateBird();
		drawBird(i_window);
	}

	void AI::uniformCrossoverWithMutation(const NodeEdgeWeights& parentWeight1, const NodeEdgeWeights& parentWeight2) {
	    // Iterate over the input to hidden weights
	    for (size_t inputIndex = 0; inputIndex < input_nodes; ++inputIndex) {
	        for (size_t hiddenIndex = 0; hiddenIndex < hidden_nodes; ++hiddenIndex) {
	            // Randomly select the weight source from either parent
	            if (rand() % 2 == 0) {
	                // If the random number is even, select weights from parentWeight1
	                Weights.InputToHiddenWeights[inputIndex][hiddenIndex] = parentWeight1.InputToHiddenWeights[inputIndex][hiddenIndex];
	                Weights.HiddenToOutputWeights[hiddenIndex][0] = parentWeight1.HiddenToOutputWeights[hiddenIndex][0];
	            } else {
	                // If the random number is odd, select weights from parentWeight2
	                Weights.InputToHiddenWeights[inputIndex][hiddenIndex] = parentWeight2.InputToHiddenWeights[inputIndex][hiddenIndex];
	                Weights.HiddenToOutputWeights[hiddenIndex][0] = parentWeight2.HiddenToOutputWeights[hiddenIndex][0];
	            }

	            // Apply mutation if necessary for both weights
	            if (MutationDistribution(RandomEngine) < MutationProbability) {
	                // If the mutation probability is met, mutate the weights
	                Weights.InputToHiddenWeights[inputIndex][hiddenIndex] = NodeDistribution(RandomEngine);
	                // std::cerr<<NodeDistribution(RandomEngine)<<"\n\n";
	                Weights.HiddenToOutputWeights[hiddenIndex][0] = NodeDistribution(RandomEngine);
	                // std::cerr<<NodeDistribution(RandomEngine)<<"\n\n...............";
	            }
	        }
	    }
	}

	void AI::resetState() {
		BirdVerticalSpeed = 0;
		BirdYPosition = 300;
	 	BirdXPosition = 170;
	  	IsAlive = true;
	  	FitnessScore = 0;
	}
}