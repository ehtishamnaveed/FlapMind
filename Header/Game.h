#ifndef GAME_H
#define GAME_H

#include <string>

namespace Game {
    extern const float gravity;

    namespace Screen {
        extern const short screenWidth;
        extern const short screenHeight;
        // String BirdTe

        // void drawBackground(sf::RenderWindow& i_window);
        void drawBackground(sf::RenderWindow& i_window, sf::Texture& background_texture, sf::Sprite& background_sprite, std::string nameOfTexture);
    }
}

#endif