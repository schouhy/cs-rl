#ifndef PLAYERANIMATION_H
#define PLAYERANIMATION_H

#include "Player.h"
#include "Layer.h"

using textures_map = std::map<std::string, std::vector<sf::Texture*>>;


class PlayerAnimation : public Layer
{
private:
    const Player& m_Player;
    sf::Sprite& m_Sprite;
    std::map<std::string, std::vector<sf::Texture*>>& m_Textures;
    int m_LastState;
    sf::Time m_TimeSinceLastUpdate;
    int m_CurrentIndex;

    sf::Clock m_Clock;

    // Functions
    void checkReset();


public:
    // Constructor / Destructor
    PlayerAnimation(const Player& player, sf::Sprite& sprite, textures_map& textures);
    ~PlayerAnimation();

    // Functions
    void update();
    void render(sf::RenderTarget *target);
};

#endif // PLAYERANIMATION_H