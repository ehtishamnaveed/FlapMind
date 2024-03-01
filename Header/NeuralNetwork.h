#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "../Header/Bird.h"
#include "../Header/Game.h"
#include "../Header/Pipe.h"
#include <chrono>
#include <random>

namespace NeuralNetwork {
	// Nodes meaning 'Neurons'
	constexpr unsigned char input_nodes = 3;
	constexpr unsigned char hidden_nodes = 4;
	constexpr unsigned char output_nodes = 1;

	struct NeuralLayers {
		// Each layer will have specific Nodes aka 'Neurons'
		float InputLayer[input_nodes];
		float HiddenLayer[hidden_nodes];
		float OutputLayer[output_nodes];
	};

	struct NodeEdgeWeights {
		// Each Input Node is connected to every Hidden Node
		float InputToHiddenWeights[input_nodes][hidden_nodes];
		// Each Hidden Node is Connect to Output Node
		float HiddenToOutputWeights[hidden_nodes][output_nodes];
	};

	// AI Class
	class AI : public Game::Bird {
	private:
		NeuralLayers Layers;
		NodeEdgeWeights Weights;

		std::mt19937_64 RandomEngine;

		//This is the range in which the weights can be.
		std::uniform_real_distribution<float> NodeDistribution;
		
	public:
		AI();
		void generateWeights();
		void calculateDifference(const std::vector<Game::Pipe>& Pipes);
		void playGame(sf::RenderWindow& i_window,const std::vector<Game::Pipe>& Pipes);
		bool shouldFlap();
		void updateBird() override;

	private:
		// unsigned char PipeGap;
		unsigned short PipeYPos;
	};
}

#endif