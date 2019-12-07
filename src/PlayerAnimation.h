#ifndef PLAYERANIMATION_H
#define PLAYERANIMATION_H

#include "Player.h"

class PlayerAnimation
{
private:
    const Player& m_Player;
    sf::Sprite& m_Sprite;
    sf::Texture& m_Texture;

public:
    // Constructor / Destructor
    PlayerAnimation(sf::Sprite& sprite, const Player& player, sf::Texture& texture);
    ~PlayerAnimation();

    // Functions
    void update();
};

#endif // PLAYERANIMATION_H