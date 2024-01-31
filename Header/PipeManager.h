#ifndef PIPEMANAGER_H
#define PIPEMANAGER_H
#include "Pipe.h"
#include <random>

namespace Game {
	class PipeManager {
	public:
		PipeManager();
		void drawPipes(sf::RenderWindow& i_window);
		void updatePipes();
		const std::vector<Pipe>& getPipes() const;

		void resetPipes();

	private:
		// Vector or "class Pipe" to store the generated pipes
		std::vector<Pipe> Pipes;
		// limit of pipes to draw at certain 
		static constexpr unsigned char PipeIndent = 170;
		
		std::mt19937_64 RandomEngine;
		unsigned short GeneratorTimer;
		std::uniform_int_distribution<unsigned short> Y_Distribution;
	};
}

#endif