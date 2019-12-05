#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "Environment.h"

class Visualization
{
private:
    Environment *m_Environment;
    sf::RectangleShape m_EntityShape;
    
public:
    // Constructor / Destructor
    Visualization(Environment *env);
    ~Visualization();

    // Functions
    void render(sf::RenderTarget *target);
};


#endif