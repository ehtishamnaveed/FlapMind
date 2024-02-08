#ifndef GAME_H
#define GAME_H
#include <sstream>
#include <fstream>
#include <string>

namespace Game {
    extern const float gravity;
    extern bool mute;

    extern std::string theme_name;
    extern unsigned short easymode_highscore;
    extern unsigned short hardmode_highscore;
    extern unsigned short crazymode_highscore;

    void loadConfiguration();
    void saveConfiguration();

    namespace Screen {
        extern const short screenWidth;
        extern const short screenHeight;
    }
}

#endif