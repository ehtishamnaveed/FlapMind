#ifndef GAME_H
#define GAME_H
#include <sstream>
#include <fstream>
#include <string>

namespace Game {
    extern const char gravity; // Gravity of Game
    extern bool mute; // Mute variable for overall Game Music and FX

    extern std::string theme_name; // Variable thats reads and saves the game's theme name

    // Variables that reads and saves the highscore for specific gamemode
    extern unsigned short easymode_highscore;
    extern unsigned short hardmode_highscore;
    extern unsigned short crazymode_highscore;

    void loadConfiguration(); // Loads the Game setting into Memory
    void saveConfiguration(); // Saves Game currect setting into 'config' file

    namespace Screen {
        extern const short screenWidth;
        extern const short screenHeight;
    }
}

#endif