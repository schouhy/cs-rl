#ifndef DEBUGLAYER_H
#define DEBUGLAYER_H

#include "Layer.h"
#include "env/Environment.h"

class DebugLayer : public Layer
{
private:
    Environment& m_Environment;
    sf::RenderWindow& m_Window;

public:
    DebugLayer(sf::RenderWindow& window, Environment& env);
    ~DebugLayer();

    void update() override;
    void render() override;
};

#endif // DEBUGLAYER_H