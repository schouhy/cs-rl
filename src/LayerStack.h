#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "Entity.h"
#include "Layer.h"

class LayerStack : public Layer
{
protected:
    std::vector<Layer*> m_Layers;
public:
    LayerStack();
    virtual ~LayerStack();

    // Functions
    void update() override;
    void render(sf::RenderTarget *target) override;
};

#endif // LAYERSTACK_H