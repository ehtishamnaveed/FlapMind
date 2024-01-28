#include <SFML/Graphics.hpp>
#include "../Header/Game.h"
#include "../Header/GameManager.h"

namespace Game {
    // Constructor initializes GameManager with default score and font settings
    GameManager::GameManager(): Score(0), gameState(GameState::None) {
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
        // Render the display including pipes, bird, and score
        renderDisplay(i_window);

        // If the Bird is alive
        while (bird.isLiving()) {
            bird.updateBird();
            pipeController.updatePipes();

            // Check for Collision
            if (collisionOfBirdWithPipes(bird, pipeController.getPipes())) {
                bird.Dies();
            }
        }

        // If the Bird is dead
        // Pause until Enter key is pressed to restart the game
        sf::Event event;
        while (i_window.waitEvent(event)) {
            eventHandler(i_window,event);
            break;
        }
    }

    // Draw pipes, bird, and score on the window
    void GameManager::renderDisplay(sf::RenderWindow& i_window) {
        pipeController.drawPipes(i_window);
        bird.drawBird(i_window);
        i_window.draw(ScoreText);
    }

    // Increment the score and update the display
    void GameManager::updateScore() {
        Score++;
        ScoreText.setString(std::to_string(Score));
    }

    bool GameManager::collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& pipes)  {
        // Extracting relevant information for collision detection
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
        pipeController.resetPipes();
    }

    // Reset the score to zero and update the display
    void GameManager::resetScore() {
        Score = 0;
        ScoreText.setString(std::to_string(Score));
    }

    // Handle window events
    void GameManager::eventHandler(sf::RenderWindow& i_window, const sf::Event& event) {
        switch (event.type) {
            // Close the window if the close button is pressed
            case sf::Event::Closed:
                i_window.close();
                break;

            // Handle key presses
            case sf::Event::KeyPressed:
                KeyPressedHandler(event.key.code);
                break;
        }
    }

    // Handle specific key presses
    void GameManager::KeyPressedHandler(const sf::Keyboard::Key& key) {
        switch (key) {
            // Start the game when the Enter key is pressed
            // case sf::Keyboard::Enter:
            //         std::cerr << "Enter\n";
            //         // gameController.runGame(window);
            //         break;

            // case sf::Keyboard::Up:
            //     std::cerr << "UP\n";
            //     Menu.moveUp();
            //     break;

            // case sf::Keyboard::Down:
            //     std::cerr << "dOWN\n";
            //     Menu.moveDown();
            //     break;
        }
    }
}