#include <SFML/Graphics.hpp>
#include <iostream>
#include "../Header/Game.h"
#include "../Header/GameManager.h"

namespace Game {
    GameManager::GameManager(): Score(0) {
        ScoreFont.loadFromFile("Resources/Font/4Brain.ttf");
        ScoreText.setFont(ScoreFont);
        ScoreText.setCharacterSize(60);
        ScoreText.setFillColor(sf::Color::Black);
        ScoreText.setPosition(Game::Screen::screenWidth/2-20 , Game::Screen::screenHeight/20-20);
        ScoreText.setString(std::to_string(Score));
    }

    void GameManager::runGame(sf::RenderWindow& i_window) {
        renderDisplay(i_window);

        bird.updateBird();
        if (bird.isLiving()) {
            pipeController.updatePipes();

            if (collisionOfBirdWithPipes(bird, pipeController.getPipes())) {
                bird.Dies();

                // Pause until Enter key is pressed
                sf::Event event;
                while (i_window.waitEvent(event)) {
                    if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Enter) {
                        // Reset game state
                        resetGameState();
                        break; // Exit the pause loop
                    }
                }
            }
        }
    }

    void GameManager::renderDisplay(sf::RenderWindow& i_window) {
        pipeController.drawPipes(i_window);
        bird.drawBird(i_window);
        i_window.draw(ScoreText);
    }

    // Updates the Score of User
    void GameManager::updateScore() {
        Score++;
        ScoreText.setString(std::to_string(Score));
    }

    bool GameManager::collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& pipes)  {
        const short bird_Xpos = bird.getXPosition();
        const float bird_Ypos = bird.getYPosition();
        const unsigned char birdSize = bird.getBirdSize();
        // range to not check for collsion for pipes
        const unsigned char birdRearRange =  bird_Xpos - birdSize;
        // range to check for collsion for pipes
        const unsigned char birdFrontRange =  bird_Xpos + birdSize;
        const unsigned char pipeGapSize = Game::Pipe::getGapSize();

        for (const Pipe& curr_pipe : pipes) {
            // Check if the pipe is behind the bird, else move on to next pipe
            if (curr_pipe.getXPosition() < birdRearRange - 1) 
                continue; 
            // Check if the pipe is range to collide with the bird
            if (curr_pipe.getXPosition() < birdFrontRange && curr_pipe.getXPosition() > birdRearRange ) {
                // Check for collision excluding the gap area
                if (bird_Ypos <= curr_pipe.getYPosition() || bird_Ypos + birdSize >= curr_pipe.getYPosition() + pipeGapSize)
                    return true; /* Collision detected */
                break;
            }
            else if (bird_Xpos > curr_pipe.getXPosition() + birdSize) {
                updateScore();
                break;
            }
        }
        return false; // No collision
    }

    void GameManager::resetGameState() {
        resetScore();
        bird.resetState();
        pipeController.resetPipes();
    }

    void GameManager::resetScore() {
        Score = 0;
        ScoreText.setString(std::to_string(Score));
    }

    void GameManager::eventHandler(sf::RenderWindow& i_window, const sf::Event& event) {
        switch (event.type) {
            case sf::Event::Closed:
                i_window.close();
                break;

            case sf::Event::KeyPressed:
                KeyPressedHandler(event.key.code);
                break;
        }
    }

    void GameManager::KeyPressedHandler(const sf::Keyboard::Key& key) {
        switch (key) {
            case sf::Keyboard::Enter:
                Game::gameState = true;
                break;
        }
    }
}