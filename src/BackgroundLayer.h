#ifndef BACKGROUNDLAYER_H
#define BACKGROUNDLAYER_H

#include "Entity.h"
#include "Layer.h"

class BackgroundLayer : public Layer
{
private:
    sf::Texture& m_Texture;
    sf::Sprite m_Sprite;

public:
    BackgroundLayer(sf::Texture& texture);
    ~BackgroundLayer();

    void update();
    void render(sf::RenderTarget *target);
};

#endif // BACKGROUNDLAYER_H