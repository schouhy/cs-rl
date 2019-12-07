#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "Environment.h"
#include "PlayerAnimation.h"

class Visualization
{
private:
    Environment *m_Environment;
    
    // Player 
    PlayerAnimation *m_PlayerAnimation;
    sf::Sprite m_PlayerSprite;
    std::vector<sf::Texture*> m_PlayerTextures;
    
public:
    // Constructor / Destructor
    Visualization(Environment *env);
    ~Visualization();

    // Initializers
    void initPlayerSprites();

    // Functions
    void updatePlayerAnimation();
    void update();
    void render(sf::RenderTarget *target);
};


#endif