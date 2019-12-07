#ifndef PLAYERANIMATION_H
#define PLAYERANIMATION_H

#include "Player.h"

class PlayerAnimation
{
private:
    const Player& m_Player;
    sf::Sprite& m_Sprite;
    std::map<std::string, std::vector<sf::Texture*>>& m_Textures;
    int m_PlayerLastState;
    sf::Time m_TimeSinceLastUpdate;
    int m_CurrentIndex;

    sf::Clock m_Clock;

public:
    // Constructor / Destructor
    PlayerAnimation(sf::Sprite& sprite, const Player& player, std::map<std::string, std::vector<sf::Texture*>>& textures);
    ~PlayerAnimation();

    // Functions
    void update();
    void checkReset();
};

#endif // PLAYERANIMATION_H