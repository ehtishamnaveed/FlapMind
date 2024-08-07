#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <filesystem> // C++17 or later
#include "../Header/Bird.h"
#include "../Header/PipeManager.h"
#include "../Header/GameMode.h"
#include "../Header/NeuralNetwork.h"
#include "../Header/Chart.h"

namespace Game {
    class GameManager {
    public:
        GameManager();
        void runAiGameplay(sf::RenderWindow& i_window); // AIGAMEPLAY
        void controlAIBehaviour(sf::RenderWindow& i_window);

        // Sound FX
        void playScoreFX(); // FX when user scores
        void playLowScoreFX(); // FX for when user scores lower than the High score
        void playHighScoreFX(); // FX for when user scores higher than the High score

        void waitForStart(sf::RenderWindow& i_window);
        void renderGame(sf::RenderWindow& i_window); // Displays the Bird,Pipes, and Backgound
        void runGame(sf::RenderWindow& i_window); // It is the main game loop logic
        bool collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& Pipes); // Checks collision of Bird with Pipes
        void drawBackground(sf::RenderWindow& i_window); // Draws the backgound for Game

        void updateScore(); // Updates the score
        void resetGameState(); // Resets the Game settings
        void resetScore(); // Resets the game score to '0'
        void setGameMode(const GameModes GameType); // It sets the Game Mode type
        void displayGameOverOverlay(sf::RenderWindow& window, unsigned short*& bestScore); // End Game Overlay

        void turnOffAiMode() { ItsAIMode = false; }
        void showAiInfo(sf::RenderWindow& window, sf::RectangleShape& background, sf::Text& info_text);

        // Saves the AI Information to 'generation_metrics.csv' file
        void saveGenerationMetrics(unsigned short generationNo,unsigned short score,unsigned short bestFitness);

    private:
        bool ItsAIMode; // Differentiates between 'User' and 'AI'
        unsigned short Generation; // Keeps track of the current generation number in the genetic algorithm.
        unsigned short AiHighScore;
        unsigned short AliveBirds;
        unsigned char Mutation; // Tells about the No. of Mutated Birds

        static constexpr unsigned char PopulationSize = 10;
        NeuralNetwork::AI BirdAI[PopulationSize]; // THE AI
        Bird bird;
        PipeManager PipeController;

        // AI Visualizer
        // Chart* LineChart;

        // Score Attributes
        unsigned short Score;
        sf::Text ScoreText;
        sf::Font ScoreFont;
        
        // I am using this variable to update the score
        // For AI birds to count it as singular for the entire Population of birds
        bool RecentScoreUpdate; // Flag to indicate if the score has been updated for any AI birds

        sf::Texture background_texture;
        sf::Sprite background_sprite;

        // Sound FX
        sf::SoundBuffer FXsound;
        sf::Sound FX;
    };
}

#endif