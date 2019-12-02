#ifndef VISUALIZATION_H
#define VISUALIZATION_H

#include "Environment.h"

class Visualization
{
private:
    const Environment *m_Environment;
    sf::RectangleShape m_EntityShape;
    
public:
    // Constructor / Destructor
    Visualization(Environment *env);
    ~Visualization();

    // Functions
    void update();
    void render(sf::RenderTarget *target);
};


#endif