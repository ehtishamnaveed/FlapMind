#include <SFML/Graphics.hpp>
#include "../Header/Game.h"
#include "../Header/GameManager.h"

namespace Game {
    // Constructor initializes GameManager with default score and font settings
    GameManager::GameManager(): Score(0) {
        // Load font from file
        ScoreFont.loadFromFile("Resources/Font/4Brain.ttf");

        // Set up ScoreText properties
        ScoreText.setFont(ScoreFont);
        ScoreText.setCharacterSize(60);
        ScoreText.setFillColor(sf::Color::Black);
        ScoreText.setPosition(Game::Screen::screenWidth/2-20 , Game::Screen::screenHeight/20-20);
        ScoreText.setString(std::to_string(Score));
    }

    // Main game loop logic
    void GameManager::runGame(sf::RenderWindow& i_window) {
        // If the Bird is alive
        while (i_window.isOpen() && bird.isLiving()) {
            // Handle window closing event
            sf::Event event;
            while (i_window.pollEvent(event)) {
                if (event.type == sf::Event::Closed){
                    Game::saveConfiguration();
                    i_window.close();
                }
            }

            // Render the display including pipes, bird, and score
            renderGame(i_window);
            i_window.display();

            // Check for Collision
            if (collisionOfBirdWithPipes(bird, PipeController.getPipes())) {
                // If collides, The bird Dies
                bird.Dies();
            }
        }
    }


    // Draw pipes, bird, and score on the window
    void GameManager::renderGame(sf::RenderWindow& i_window) {
        // Updates Bird Postion
        bird.updateBird();
        // Updates Pipes position
        PipeController.updatePipes();
        //Draws the Background
        drawBackground(i_window);
        // Displays Pipe
        PipeController.drawPipes(i_window);
        // Diaplsys Bird
        bird.drawBird(i_window);
        // Displays Score
        i_window.draw(ScoreText);
    }

    // Increment the score and update the display
    void GameManager::updateScore() {
        Score++;
        ScoreText.setString(std::to_string(Score));
    }

    bool GameManager::collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& pipes) {
        const unsigned char collisionAnomaly = 6;
        // Extracting relevant information for collision detection
        const short bird_Xpos = bird.getXPosition();
        const short bird_Ypos = bird.getYPosition();
        const char birdSize = bird.getBirdSize();
        // range to not check for collsion for pipes
        const unsigned char birdRearRange =  bird_Xpos - birdSize;
        // range to check for collsion for pipes
        const unsigned char birdFrontRange =  bird_Xpos + birdSize;

        for (const Pipe& curr_pipe : pipes) {
            // Check if the pipe is behind the bird, else move on to next pipe
            if (curr_pipe.getXPosition() < birdRearRange - curr_pipe.getPipeSpeed()) 
                continue; 
            // Check if the pipe is range to collide with the bird
            if (curr_pipe.getXPosition() < birdFrontRange - collisionAnomaly && curr_pipe.getXPosition() > birdRearRange) {
                // Check for collision excluding the gap area
                // Pipe's Upper Portion ---------- OR ---------- Pipe's Lower Portion
                if (bird_Ypos <= curr_pipe.getYPosition() - collisionAnomaly || bird_Ypos + birdSize >= curr_pipe.getYPosition() + curr_pipe.getGapSize() + collisionAnomaly)
                    return true; /* Collision detected */
                break;
            }
            // Check for scoring (bird passed the pipe)
            else if (bird_Xpos > curr_pipe.getXPosition() + birdSize) {
                updateScore();
                break;
            }
        }
        return false; // No collision
    }

    // Reset the game state to start a new game
    void GameManager::resetGameState() {
        resetScore();
        bird.resetState();
        PipeController.resetPipes();
    }

    // Reset the score to zero and update the display
    void GameManager::resetScore() {
        Score = 0;
        ScoreText.setFillColor(sf::Color::Black);
        ScoreText.setString(std::to_string(Score));
        ScoreText.setCharacterSize(60);
        ScoreText.setPosition(Game::Screen::screenWidth/2-20 , Game::Screen::screenHeight/20-20);
    }

    // Draw the Backgound for Play Menu
    void GameManager::drawBackground(sf::RenderWindow& i_window) {
        background_texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/Background.png");
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }

    void GameManager::setGameMode(const GameModes GameType) {
         PipeController.setSettings(GameType);
    }

    void GameManager::displayGameOverOverlay(sf::RenderWindow& window, unsigned short*& bestScore) {
        sf::Texture texture;
        sf::Sprite sprite;
        texture.loadFromFile("Resources/Images/Scoreboard.png");

        // Calculate texture rect size only once
        sf::IntRect rect;
            if (Score > *bestScore) {
                *bestScore = Score;
                rect = sf::IntRect(300, 0, 300, 150);
            }
            else {
                rect = sf::IntRect(0, 0, 300, 150);

                // Gamplay Score
                ScoreText.setCharacterSize(40);
                ScoreText.setPosition(350 , 205);
            }

        // Set texture rect, texture, and position for the sprite
        sprite.setTextureRect(rect);
            sprite.setTexture(texture);
            sprite.setPosition(Game::Screen::screenWidth/2-160, Game::Screen::screenHeight/2-100);
        // Draw the sprite
        window.draw(sprite);
        // Draw Gamplay Score
        window.draw(ScoreText);

        // Draw High Score
        ScoreText.setString(std::to_string(*bestScore));
            ScoreText.setCharacterSize(40);
            ScoreText.setPosition(350 , 255);
            window.draw(ScoreText);

        window.display();
    }

}