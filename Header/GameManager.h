#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Bird.h"
#include "PipeManager.h"
#include "GameMode.h"

namespace Game {
    enum class GameState {
        InGame,
        GameOver,
        Exit
    };

    class GameManager {
    public:
        GameManager();
        void renderGame(sf::RenderWindow& i_window);
        void runGame(sf::RenderWindow& i_window);
        bool collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& Pipes) ;
        void drawBackground(sf::RenderWindow& i_window);

        void updateScore();
        void resetGameState();
        void resetScore();
        void setGameMode(const GameModes GameType);
        void displayGameOverOverlay(sf::RenderWindow& window, unsigned short*& bestScore);

    private:
        Bird bird;
        PipeManager PipeController;

        // Score Attributes
        unsigned short Score;
        sf::Text ScoreText;
        sf::Font ScoreFont;

        sf::Texture background_texture;
        sf::Sprite background_sprite;
    };
}

#endif