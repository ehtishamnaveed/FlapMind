#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Bird.h"
#include "PipeManager.h"

namespace Game {
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

    private:
        Bird bird;
        PipeManager pipeController;

        // Score Attributes
        unsigned short Score;
        sf::Text ScoreText;
        sf::Font ScoreFont;

        sf::Texture background_texture;
        sf::Sprite background_sprite;
    };
}

#endif