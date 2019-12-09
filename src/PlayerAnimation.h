#ifndef PLAYERANIMATION_H
#define PLAYERANIMATION_H

#include "Player.h"
#include "Layer.h"

using textures_map = std::map<std::string, std::vector<sf::Texture*>>;


class PlayerAnimation : public Layer
{
private:
    const Player& m_Player;
    sf::Sprite m_Sprite;
    const sf::Color m_Color; // Borrar?
    std::map<std::string, std::vector<sf::Texture*>>& m_Textures;
    
    sf::Clock m_Clock;
    sf::Time m_TimeSinceLastUpdate;
    int m_LastState;
    int m_CurrentIndex;
    
    // Functions
    void checkReset();
    void transform();
    void playNextFrame(std::string key, int speed_factor);

public:
    // Constructor / Destructor
    PlayerAnimation(const Player& player, textures_map& textures);
    PlayerAnimation(const Player& player, textures_map& textures, sf::Color color);
    ~PlayerAnimation();

    // Functions
    void update();
    void render(sf::RenderTarget *target);
};

#endif // PLAYERANIMATION_H