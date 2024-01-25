#include <SFML/Graphics.hpp>
#include "../Header/Game.h"

namespace Game {
    const float gravity = 0.25f;
    bool gameState = false;

    namespace Screen {
        const short screenWidth = 600;
        const short screenHeight = 600;

        void drawScreen(sf::RenderWindow& i_window, sf::Texture& background_texture, sf::Sprite& background_sprite, std::string nameOfTexture) {
            background_texture.loadFromFile("Resources/Images/" + nameOfTexture);
            background_sprite.setTexture(background_texture);
            i_window.draw(background_sprite);
        }
    }
}