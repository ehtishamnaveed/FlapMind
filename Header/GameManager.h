#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include "Bird.h"
#include "PipeManager.h"

namespace Game {

    enum class GameState {
        None,
        MainMenu,
        Playing,
        GameOver,
    };

    class GameManager {
    public:
        GameManager();
        void renderDisplay(sf::RenderWindow& i_window);
        void runGame(sf::RenderWindow& i_window);
        bool collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& Pipes) ;

        void updateScore();
        void resetGameState();
        void resetScore();

        // Event Handler functions
        void KeyPressedHandler(const sf::Keyboard::Key&);
        void eventHandler(sf::RenderWindow& i_window, const sf::Event& event);

    private:
        GameState gameState;
        Bird bird;
        PipeManager pipeController;

        // Score Attributes
        unsigned short Score;
        sf::Text ScoreText;
        sf::Font ScoreFont;
    };
}

#endif