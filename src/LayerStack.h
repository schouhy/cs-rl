#ifndef LAYERSTACK_H
#define LAYERSTACK_H

#include "Entity.h"
#include "Layer.h"

class LayerStack : public Layer
{
protected:
    std::vector<Layer*> m_Layers;
public:
    LayerStack(sf::RenderWindow& window);
    virtual ~LayerStack();

    // Functions
    void update() override;
    void render() override;
};

#endif // LAYERSTACK_H