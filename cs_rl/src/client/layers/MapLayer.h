#ifndef MAPLAYER_H
#define MAPLAYER_H

#include "Layer.h"

class MapLayer : public Layer
{
private:
    sf::Texture& m_Texture;
    sf::Sprite m_Sprite;

public:
    MapLayer(sf::RenderWindow& window, sf::Texture& texture);
    ~MapLayer() = default;

    void update() override;
    void render() override;
};

#endif // MAPLAYER_H