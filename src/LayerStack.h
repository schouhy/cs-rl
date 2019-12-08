#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "Entity.h"
#include "Layer.h"

class LayerStack
{
protected:
    std::vector<Layer*> m_Layers;
public:
    LayerStack();
    virtual ~LayerStack();

    // Functions
    void update();
    void render(sf::RenderTarget *target);
};

#endif // LAYERSTACK_H