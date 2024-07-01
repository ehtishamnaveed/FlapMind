#include <SFML/Graphics.hpp>
#include "../Header/Game.h"

namespace Game {
    // Game's Gravity
    constexpr float gravity = 0.90f;

    // Variable for Game Sound FX
    bool mute = false;

    // Variable to load Theme name form file
    std::string theme_name;

    // Variables to Load High score
    // for different Modes
    // from file
    unsigned short easymode_highscore;
    unsigned short hardmode_highscore;
    unsigned short crazymode_highscore;

    // Loads Game settings from file
    void loadConfiguration() {
        std::ifstream inputFile("config.txt");
        if (!inputFile) {
            // File doesn't exist, initialize with default values
            theme_name = "clearsky";
            easymode_highscore = 0;
            hardmode_highscore = 0;
            crazymode_highscore = 0;
            mute = true;
            return;
        }
        
        // File exists, read data
        std::string info;
        bool anyDataRead = false;
        while (std::getline(inputFile, info)) {
            std::istringstream data(info);
            if (data >> theme_name >> easymode_highscore >> hardmode_highscore >> crazymode_highscore >> mute) {
                anyDataRead = true;
            }
        }
        
        if (!anyDataRead) {
            // File was empty, initialize with default values
            theme_name = "clearsky";
            easymode_highscore = 0;
            hardmode_highscore = 0;
            crazymode_highscore = 0;
            mute = true;
        }
        inputFile.close();
    }

    // Stores Game setting to file
    void saveConfiguration() {
        std::ofstream outputFile("config.txt");
        if (outputFile) {
            outputFile << theme_name << " "
                       << easymode_highscore << " "
                       << hardmode_highscore << " "
                       << crazymode_highscore << " "
                       << mute;
            outputFile.close();
        }
    }

    namespace Screen {
        constexpr short screenWidth = 600;
        constexpr short screenHeight = 600;
    }
}