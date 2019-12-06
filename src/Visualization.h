#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "Environment.h"

class Visualization
{
private:
    Environment *m_Environment;
    sf::CircleShape m_EntityShape;
    
public:
    // Constructor / Destructor
    Visualization(Environment *env);
    ~Visualization();

    // Functions
    void update();
    void render(sf::RenderTarget *target);
};


#endif