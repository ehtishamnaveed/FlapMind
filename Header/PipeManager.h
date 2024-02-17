#ifndef PIPEMANAGER_H
#define PIPEMANAGER_H
#include "../Header/Pipe.h"
#include <random>

namespace Game {
	class PipeManager {
	public:
		PipeManager();
		void drawPipes(sf::RenderWindow& i_window);
		void updatePipes();
		const std::vector<Pipe>& getPipes() const;
		void resetPipes(); // Removes the Pipes from Vector

		// Sets 'PipeIndent' and  'GeneratorDuration'
		// for the specific GameMode type
		void setSettings(GameModes GameType);
		// Sets pipe settings for AI
		void setAISettings();
		
		// Getters
		const std::uniform_int_distribution<unsigned short>& getYDistribution() const;
		const unsigned char& getPipeIndent() const;


	private:
		GameModes GameType;
		// Vector of "class Pipe" to store the generated pipes
		std::vector<Pipe> Pipes;

		std::mt19937_64 RandomEngine;
		unsigned short GeneratorTimer;
		std::uniform_int_distribution<unsigned short> Y_Distribution;

		unsigned char PipeIndent;
		unsigned char GeneratorDuration;

		// Variables for Easy gamemode
		static constexpr unsigned char EasyPipeIndent = 200;
		static constexpr unsigned char EasyGeneratorDuration = 100;

		// Variables for Hard gamemode
		static constexpr unsigned char HardPipeIndent = 250;
		static constexpr unsigned char HardGeneratorDuration = 40;

		// Variables for Crazy gamemode
		static constexpr unsigned char CrazyPipeIndent = 230;
		static constexpr unsigned char CrazyGeneratorDuration = 50;
	};
}

#endif