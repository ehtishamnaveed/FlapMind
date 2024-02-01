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
		void setSettings(GameModes GameType);


	private:
		GameModes GameType;
		// Vector or "class Pipe" to store the generated pipes
		std::vector<Pipe> Pipes;

		std::mt19937_64 RandomEngine;
		unsigned short GeneratorTimer;
		std::uniform_int_distribution<unsigned short> Y_Distribution;

		unsigned char PipeIndent;
		unsigned char GeneratorDuration;

		static constexpr unsigned char EasyPipeIndent = 200;
		static constexpr unsigned char EasyGeneratorDuration = 150;

		static constexpr unsigned char HardPipeIndent = 250;
		static constexpr unsigned char HardGeneratorDuration = 80;

		static constexpr unsigned char CrazyPipeIndent = 200;
		static constexpr unsigned char CrazyGeneratorDuration = 150;
	};
}

#endif