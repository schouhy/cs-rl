#ifndef LAYER_H
#define LAYER_H

#include "Entity.h"

class Layer
{
public:
    // Constructor / Destructor
    Layer();
    virtual ~Layer();

    // Functions
    virtual void update() = 0;
    virtual void render(sf::RenderTarget *target) = 0;
};

#endif // LAYER_H