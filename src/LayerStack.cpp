#include "LayerStack.h"

LayerStack::LayerStack()
{
}

LayerStack::~LayerStack()
{
    for (auto layer : m_Layers)
        delete layer;
}

void LayerStack::update()
{
    for (auto layer : m_Layers)
        layer->update();
}

void LayerStack::render(sf::RenderTarget *target)
{
    for (auto layer : m_Layers)
        layer->render(target);
}