#include <SFML/Graphics.hpp>
#include "../Header/Game.h"
#include "../Header/GameManager.h"
#include "../Header/EventHandler.h"

namespace Game {
    // Constructor initializes GameManager with default score and font settings
    GameManager::GameManager(): Score(0), RecentScoreUpdate(false), ItsAIMode(false) {
        // Load font from file
        ScoreFont.loadFromFile("Resources/Font/4Brain.ttf");

        // Set up ScoreText properties
        ScoreText.setFont(ScoreFont);
        ScoreText.setCharacterSize(60);
        ScoreText.setFillColor(sf::Color::Black);
        ScoreText.setPosition(Game::Screen::screenWidth/2-20 , Game::Screen::screenHeight/20-20);
        ScoreText.setString(std::to_string(Score));
    }

    void GameManager::runAiGameplay(sf::RenderWindow& i_window) {
        // Temporary instance to handle AI Gameplay Events
        Game::EventHandler* EventManager = new EventHandler();

        // Enable Ai Mode, cuz its AI Gameplay
        ItsAIMode = true;

        // Generating Edge Weights for each bird population
        for (NeuralNetwork::AI& aibirds : BirdAI) {
            aibirds.generateEdgeWeights();
        }

        // Main AI Gameplay loop
        while (i_window.isOpen()) {
            i_window.clear();
            
            // Handle events
            sf::Event event;
            while (i_window.pollEvent(event)) {
                // Handle window closing event
                if (event.type == sf::Event::Closed){
                    // Clean up temporary memory first
                    delete EventManager;
                    // then close the window
                    i_window.close();
                    break;
                }

                // Handle Gameplay key press event
                else if (event.type == sf::Event::KeyPressed) {
                    EventManager->processAiGameplayKeyPressed(event.key.code, PipeController, *this);

                    // Check if AI mode is disabled
                    if (!ItsAIMode) {
                        // Reset AI state
                        for (NeuralNetwork::AI& aibirds : BirdAI) {
                            aibirds.resetState();
                        }

                        // Reset Pipes
                        PipeController.resetPipes();

                        // Reset Score
                        resetScore();

                        // Clean up temporary memory 
                        delete EventManager;

                        // Gameplay is Over 
                        return;
                    }
                }
            }
            // Draws Backgound
            drawBackground(i_window);

            // Updates and Draws Pipes
            PipeController.updatePipes();
            PipeController.drawPipes(i_window);

            // Ai controler
            controlAIBehaviour(i_window);

            // Displays Score
            i_window.draw(ScoreText);

            // Displays Window
            i_window.display();
        } 
    }

    void GameManager::controlAIBehaviour(sf::RenderWindow& i_window) {
        RecentScoreUpdate = false;
        bool needrestart = true;

        // Check if any bird is alive from population
        for (NeuralNetwork::AI& aibird : BirdAI) {
            // If even one bird is found alive
            if (aibird.isAlive()) {
                // we wont restart the simulation
                needrestart = false;
                break;
            }
        }

        // If don't need to restart the simulation
        if (!needrestart) {
            // Keep the AI play the game
            for (NeuralNetwork::AI& aibird : BirdAI) {
                // AI updates position and learns to flap
                aibird.playGame(i_window,PipeController.getPipes());

                // After updating the position of the bird
                // Check if the bird is alive
                if (aibird.isAlive()) {
                    // Check for Collision
                    if (collisionOfBirdWithPipes(aibird, PipeController.getPipes())) {
                        // If collides, The bird Dies
                        aibird.Dies();
                    }
                }
                // Else continue to the next bird
                else continue;
            }
        }
        else {
            // Sorting the Fitness of birds ( greater to smaller ) 
            // std::sort will use the operator functions in the AI class.
            std::sort(std::begin(BirdAI), std::end(BirdAI), std::greater<>());

            // We won't change the weights of the first 2 birds since they're the BEST!
            for (size_t curr_bird = 2 ; curr_bird < PopulationSize ; ++curr_bird) {
                BirdAI[curr_bird].uniformCrossoverWithMutation(BirdAI[0].getWeights(), BirdAI[1].getWeights());
            }

            // We reset the AI, Pipes and Score
            for (NeuralNetwork::AI& aibirds : BirdAI) {
                aibirds.resetState();
            }
            PipeController.resetPipes();
            resetScore();
        }
    }

    // Play Score FX
    void GameManager::playScoreFX() {
        if (!Game::mute) {
            // Load sound files into sound buffers
            FXsound.loadFromFile("Resources/SoundFX/ScoreFX.mp3");

            // Associate sound buffers with sound objects
            FX.setBuffer(FXsound);
            FX.play();
        }
    }

    // Play LowScore FX
    void GameManager::playLowScoreFX() {
        if (!Game::mute) {
            // Load sound files into sound buffers
            FXsound.loadFromFile("Resources/SoundFX/LowScoreFX.mp3");

            // Associate sound buffers with sound objects
            FX.setBuffer(FXsound);
            FX.play();
        }
    }

    // Play HighScore FX
    void GameManager::playHighScoreFX() {
        if (!Game::mute) {
            // Load sound files into sound buffers
            FXsound.loadFromFile("Resources/SoundFX/HighScoreFX.mp3");

            // Associate sound buffers with sound objects
            FX.setBuffer(FXsound);
            FX.play();
        }
    }

    // Main game loop logic
    void GameManager::runGame(sf::RenderWindow& i_window) {
        // If the Bird is alive
        while (i_window.isOpen() && bird.isAlive()) {
            sf::Event event;
            while (i_window.pollEvent(event)) {
                // Handle window closing event
                if (event.type == sf::Event::Closed){
                    i_window.close();
                    break;
                }
            }

            // Render the display including pipes, bird, and score
            renderGame(i_window);

            // Check for Collision
            if (collisionOfBirdWithPipes(bird, PipeController.getPipes())) {
                // If collides, The bird Dies
                bird.Dies();
            }
        }
    }


    // Draw pipes, bird, and score on the window
    void GameManager::renderGame(sf::RenderWindow& i_window) {
        i_window.clear();
        // Draw the Background
        drawBackground(i_window);
        // Updates Pipes position
        PipeController.updatePipes();
        // Displays Pipe
        PipeController.drawPipes(i_window);
        // Updates Bird Position
        bird.updateBird();
        // Displays Bird
        bird.drawBird(i_window);
        // Displays Score
        i_window.draw(ScoreText);
        // Display everything on the window
        i_window.display();
    }


    // Increment the score
    void GameManager::updateScore() {
        // This check is made to differentiate 
        // between AI and User Mode
        if (ItsAIMode) {
            if (!RecentScoreUpdate) {
                RecentScoreUpdate = true;
                Score++;
                ScoreText.setString(std::to_string(Score));
            }
        }
        else {
            Score++;
            ScoreText.setString(std::to_string(Score));
        }
    }


    // Collision Detection
    bool GameManager::collisionOfBirdWithPipes(const Bird& bird, const std::vector<Pipe>& pipes) {
        // Anomally, to make collsion look good visually
        const unsigned char collisionAnomaly = 8;

        // Bird Information
        const short birdSize = bird.getBirdSize();
        const short birdXPos = bird.getXPosition();
        const short birdYPos = round(bird.getYPosition());

        // Loop through pipes
        for (const Pipe& curr_pipe : pipes) {
            // Pipe information
            const short pipeXPos = curr_pipe.getXPosition();
            const short pipeYPos = curr_pipe.getYPosition();
            const unsigned char pipeGapSize = curr_pipe.getGapSize();
            const char pipeSpeed = curr_pipe.getPipeSpeed();
            const unsigned char pipeWidth = curr_pipe.getPipeWidth();

            // Collision vertical boundaries for the pipe
            const short pipeTop = pipeYPos - collisionAnomaly;
            const short pipeBottom = pipeYPos + pipeGapSize + collisionAnomaly;

            // Info about when not to check for collision
            const bool pipeIsBehindTheBird = pipeXPos < (birdXPos - birdSize - pipeSpeed);

            // Info about bird scoring
            const bool birdPassedThePipe = birdXPos > (pipeXPos + birdSize);

            // Collision Range information
            const bool pipeInCollisionRange = (pipeXPos <= birdXPos + birdSize) && (pipeXPos + pipeWidth >= birdXPos);

            if (pipeIsBehindTheBird)
                continue; // Continue to the next pipe then
            // And skip the below statemnts

            if (pipeInCollisionRange) {
                // Check for collision excluding the gap area
                if (birdYPos <= pipeTop || birdYPos + birdSize >= pipeBottom)
                    return true; // Collision detected
                break;
            }

            else if (birdPassedThePipe) {
                updateScore();
                playScoreFX();
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


    void GameManager::waitForStart(sf::RenderWindow& i_window) {
        drawBackground(i_window);
        bird.drawBird(i_window);

        ScoreText.setCharacterSize(40);
        ScoreText.setString("Press Up / Space to Flap");
        ScoreText.setPosition(50,250);
        i_window.draw(ScoreText);

        i_window.display();

        while (i_window.isOpen()) {
            // Check for events
            sf::Event event;
            while (i_window.waitEvent(event)) {
                // Check Event Type
                switch (event.type) {
                    // Window closing event
                    case sf::Event::Closed:
                        i_window.close();
                        return;

                    // Key Pressed Events
                    case sf::Event::KeyPressed:
                        // Check for the Keys
                        switch(event.key.code) {
                            case sf::Keyboard::Up:
                            case sf::Keyboard::Space:
                                resetScore();
                                return;
                        }
                        break;
                }
            }
        }
    }


    // Reset the score to zero and update the display
    void GameManager::resetScore() {
        Score = 0;
        ScoreText.setFillColor(sf::Color::Black);
        ScoreText.setString(std::to_string(Score));
        ScoreText.setCharacterSize(60);
        ScoreText.setPosition(Game::Screen::screenWidth/2-20 , Game::Screen::screenHeight/20-20);
        ScoreText.setString(std::to_string(Score));
    }


    // Draw the Backgound for Play Menu
    void GameManager::drawBackground(sf::RenderWindow& i_window) {
        background_texture.loadFromFile("Resources/Theme/"+Game::theme_name+"/Background.png");
        background_sprite.setTexture(background_texture);
        i_window.draw(background_sprite);
    }


    // It sets the Game Mode type
    void GameManager::setGameMode(const GameModes GameType) {
         PipeController.setSettings(GameType);
    }


    // End Game Overlay
    void GameManager::displayGameOverOverlay(sf::RenderWindow& window, unsigned short*& bestScore) {
        sf::Texture texture;
        sf::Sprite sprite;
        texture.loadFromFile("Resources/Images/Scoreboard.png");

        sf::IntRect rect;
            if (Score > *bestScore) {
                playHighScoreFX();
                *bestScore = Score;
                rect = sf::IntRect(300, 0, 300, 150);
            }
            else {
                playLowScoreFX();
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
            ScoreText.setPosition(350 , 253);
            window.draw(ScoreText);

        window.display();
    }
}