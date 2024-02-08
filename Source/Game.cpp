#include <SFML/Graphics.hpp>
#include "../Header/Game.h"

namespace Game {
    // Game's Gravity
    const float gravity = 0.90f;

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
        // Open the configuration file to read
        std::ifstream inputFile("config.txt");
        std::string info;
        while (std::getline(inputFile,info)) {
            std::istringstream data(info);
            data  >> theme_name >> easymode_highscore >> hardmode_highscore >> crazymode_highscore >> mute;
        }
        inputFile.close();
    }

    // Stores Game setting from file
    void saveConfiguration() {
        // Open the Configuration to write
        std::ofstream outputFile("config.txt");
        outputFile << theme_name
                   << " " << easymode_highscore
                   << " " << hardmode_highscore
                   << " " << crazymode_highscore
                   << " " << mute;
        outputFile.close();
    }

    namespace Screen {
        const short screenWidth = 600;
        const short screenHeight = 600;
    }
}