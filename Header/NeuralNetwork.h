#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "../Header/Bird.h"
#include "../Header/Game.h"
#include "../Header/Pipe.h"
#include <chrono>
#include <random>

namespace NeuralNetwork {
	// Nodes meaning 'Neurons'
	constexpr unsigned char input_nodes = 2;
	constexpr unsigned char hidden_nodes = 3;
	constexpr unsigned char output_nodes = 1;

	struct NeuralLayers {
		// Each layer will have specific Nodes aka 'Neurons'
		float InputLayer[input_nodes];
		float HiddenLayer[hidden_nodes];
		float OutputLayer[output_nodes];
	};

	struct NodeEdgeWeights {
		// Input to Hidden Nodes Weights
		float InputToHiddenWeights[input_nodes][hidden_nodes];
		// Hidden to Output Nodes Weights
		float HiddenToOutputWeights[hidden_nodes][output_nodes];
	};

	// AI Class
	class AI : public Game::Bird {	
	public:
		AI();
		void generateEdgeWeights(); // Generates Weight for the Edges for each Node for every layers
		// This function does what the below 2 functions name suggest
		bool activationFunction();
		void feedforwardToHiddenLayer();
		void feedforwardToOutputLayer();

		void calculateDifference(const std::vector<Game::Pipe>& Pipes);
		void playGame(sf::RenderWindow& i_window,const std::vector<Game::Pipe>& Pipes);
		bool shouldFlap();
		void updateBird() override;
		void resetState() override;
		
		void updateFitness();
		unsigned getFitness() { return Fitness; }
		bool operator<(AI& i_bird) { return Fitness < i_bird.getFitness(); }
		bool operator>(AI& i_bird) { return Fitness > i_bird.getFitness(); }

		NodeEdgeWeights& getWeights() { return Weights; }

		void uniformCrossoverWithMutation(const NodeEdgeWeights& parentWeight1, const NodeEdgeWeights& parentWeight2);

	private:
		NeuralLayers Layers;
		NodeEdgeWeights Weights;

		std::mt19937_64 RandomEngine;
		// std::minstd_rand RandomEngine;

		//This is the range in which the weights can be.
		std::uniform_real_distribution<float> NodeDistribution;

		static constexpr unsigned char MutationProbability = 24;
		std::uniform_int_distribution<unsigned short> MutationDistribution;

		float BirdNPipeDifference;

		unsigned Fitness;
	};
}

#endif