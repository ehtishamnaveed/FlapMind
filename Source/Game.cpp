#include <SFML/Graphics.hpp>
#include "../Header/Game.h"

namespace Game {
    const float gravity = 0.90f;
    std::string theme_name;
    unsigned short easymode_highscore;
    unsigned short hardmode_highscore;
    unsigned short crazymode_highscore;

    void loadConfiguration() {
        // Open the configuration file to read
        std::ifstream inputFile("config.txt");
        std::string info;
        while (std::getline(inputFile,info)) {
            std::istringstream data(info);
            data  >> theme_name >> easymode_highscore >> hardmode_highscore >> crazymode_highscore;
        }
        inputFile.close();
    }

    void saveConfiguration() {
        // Open the Configuration to write
        std::ofstream outputFile("config.txt");
        outputFile << theme_name
                   << " " << easymode_highscore
                   << " " << hardmode_highscore
                   << " " << crazymode_highscore;
        outputFile.close();
    }

    namespace Screen {
        const short screenWidth = 600;
        const short screenHeight = 600;
    }
}