#ifndef PLAYERVISUALIZATION_H
#define PLAYERVISUALIZATION_H

#include "PlayerAnimation.h"
#include "LayerStack.h"

using textures_map = std::map<std::string, std::vector<sf::Texture*>>;

class PlayerVisualization : public LayerStack
{
private:
    //const Player& m_Player;
    sf::Sprite m_BodySprite;
    sf::Sprite m_FeetSprite;
    textures_map& m_BodyTextures;
    textures_map& m_FeetTextures;

public:
    // Constructor / Destructor
    PlayerVisualization(const Player& player, textures_map& body_textures, textures_map& feet_textures);
};

#endif // PLAYERANIMATION_H