#ifndef NEURALNETWORK_H
#define NEURALNETWORK_H
#include "../Header/Bird.h"
#include "../Header/Game.h"
#include "../Header/Pipe.h"

namespace NeuralNetwork {
	class AI : public Game::Bird {
	public:
		// AI();
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