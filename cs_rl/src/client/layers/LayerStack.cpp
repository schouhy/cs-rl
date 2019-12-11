#include "LayerStack.h"

LayerStack::LayerStack(sf::RenderWindow& window)
    : Layer(window)
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

void LayerStack::render()
{
    for (auto layer : m_Layers)
        layer->render();
}