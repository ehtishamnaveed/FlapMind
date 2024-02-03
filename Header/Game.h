#ifndef GAME_H
#define GAME_H
#include <sstream>
#include <fstream>
#include <string>

namespace Game {
    extern const float gravity;

    extern std::string theme_name;

    void loadConfiguration();
    void saveConfiguration();

    namespace Screen {
        extern const short screenWidth;
        extern const short screenHeight;
    }
}

#endif