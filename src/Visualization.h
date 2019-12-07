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
    std::map<std::string, std::vector<sf::Texture*>> m_PlayerTextures;

    // Initializers
    void initPlayerSprites();

    // Functions
    void updatePlayerAnimation();
    void loadTexturesFromFolder(std::string path, std::string key);

public:
    // Constructor / Destructor
    Visualization(Environment *env);
    ~Visualization();

    // Functions
    void update();
    void render(sf::RenderTarget *target);
};


#endif