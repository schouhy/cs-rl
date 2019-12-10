#ifndef PLAYERANIMATION_H
#define PLAYERANIMATION_H

#include "Player.h"
#include "Layer.h"

using textures_map = std::map<std::string, std::vector<sf::Texture*>>;


class PlayerSpriteLayer : public Layer
{
private:
    const Player& m_Player;
    sf::Sprite m_Sprite;
    const sf::Color m_Color; // Borrar?
    textures_map& m_Textures;
    
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
    PlayerSpriteLayer(const Player& player, textures_map& textures);
    PlayerSpriteLayer(const Player& player, textures_map& textures, sf::Color color);
    ~PlayerSpriteLayer() = default;

    // Functions
    void update() override;
    void render(sf::RenderTarget *target) override;
};

#endif // PLAYERANIMATION_H