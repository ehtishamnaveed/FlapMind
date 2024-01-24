#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Bird.h"
#include "PipeManager.h"

namespace Game {
    class GameManager {
    public:
        GameManager();
        void renderDisplay(sf::RenderWindow& i_window);
        void run(sf::RenderWindow& i_window);
        bool collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& Pipes) ;

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
    };
}

#endif