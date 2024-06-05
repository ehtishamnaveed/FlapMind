#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "../Header/Bird.h"
#include "../Header/PipeManager.h"
#include "../Header/GameMode.h"
#include "../Header/NeuralNetwork.h"

namespace Game {
    class GameManager {
    public:
        GameManager();
        bool aiGameplay(sf::RenderWindow& i_window); // AIGAMEPLAY
        void controlAIBehaviour(sf::RenderWindow& i_window);
        // Sound FX
        void playScoreFX(); // FX when user scores
        void playLowScoreFX(); // FX for when user scores lower than the High score
        void playHighScoreFX(); // FX for when user scores higher than the High score

        void renderGame(sf::RenderWindow& i_window); // Displays the Bird,Pipes, and Backgound
        void runGame(sf::RenderWindow& i_window); // It is the main game loop logic
        bool collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& Pipes); // Checks collision of Bird with Pipes
        void drawBackground(sf::RenderWindow& i_window); // Draws the backgound for Game

        void updateScore(); // Updates the score of the user
        void resetGameState(); // Resets the Game settings
        void resetScore(); // Resets the game score to '0'
        void setGameMode(const GameModes GameType); // It sets the Game Mode type
        void displayGameOverOverlay(sf::RenderWindow& window, unsigned short*& bestScore); // End Game Overlay

    private:
        bool ItsAIMode;

        static constexpr unsigned char PopulationSize = 15;
        NeuralNetwork::AI BirdAI[PopulationSize]; // THE AI
        Bird bird;
        PipeManager PipeController;

        // Score Attributes
        unsigned short Score;
        sf::Text ScoreText;
        sf::Font ScoreFont;
        bool RecentScoreUpdate; // Flag to indicate if the score has been updated for any AI birds

        sf::Texture background_texture;
        sf::Sprite background_sprite;

        // Sound FX
        sf::SoundBuffer FXsound;
        sf::Sound FX;
    };
}

#endif