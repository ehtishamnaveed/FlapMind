#include <SFML/Graphics.hpp>
#include "../Header/Game.h"

namespace Game {
    const float gravity = 0.25f;
    std::string theme_name;

    void loadConfiguration() {
        // Open the configuration file to read
        std::ifstream inputFile("config.txt");
        std::string info;
        while (std::getline(inputFile,info)) {
            std::istringstream data(info);
            data  >> theme_name;
        }
        inputFile.close();
    }

    void saveConfiguration() {
        // Open the Configuration to write
        std::ofstream outputFile("config.txt");
        outputFile << theme_name;
        outputFile.close();
    }

    namespace Screen {
        const short screenWidth = 600;
        const short screenHeight = 600;
    }
}