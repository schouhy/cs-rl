#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "Environment.h"
//#include "Animation.h"

class Visualization
{
private:
    Environment *m_Environment;
    
    // Player 
    //std::map<std::string, Animation> m_Animations;
    sf::Sprite m_PlayerSprite;
    sf::Texture m_PlayerTexture;
    
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