#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "Environment.h"

class Visualization
{
private:
    Environment *m_Environment;
    
    // Player 
    sf::CircleShape m_EntityShape;
    sf::Texture m_Texture;
    sf::IntRect m_Rect;
    
public:
    // Constructor / Destructor
    Visualization(Environment *env);
    ~Visualization();

    // Functions
    void update();
    void render(sf::RenderTarget *target);
};


#endif