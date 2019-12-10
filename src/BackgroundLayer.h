#ifndef BACKGROUNDLAYER_H
#define BACKGROUNDLAYER_H

#include "Layer.h"

class BackgroundLayer : public Layer
{
private:
    sf::Texture& m_Texture;
    sf::Sprite m_Sprite;

public:
    BackgroundLayer(sf::Texture& texture);
    ~BackgroundLayer() = default;

    void update() override;
    void render(sf::RenderTarget *target) override;
};

#endif // BACKGROUNDLAYER_H