#ifndef BACKGROUNDLAYER_H
#define BACKGROUNDLAYER_H

#include "Layer.h"

class BackgroundLayer : public Layer
{
private:
    sf::Texture& m_Texture;
    sf::Sprite m_Sprite;

public:
    BackgroundLayer(sf::RenderWindow& window, sf::Texture& texture);
    ~BackgroundLayer() = default;

    void update() override;
    void render() override;
};

#endif // BACKGROUNDLAYER_H