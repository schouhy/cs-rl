#include "BackgroundLayer.h"


BackgroundLayer::BackgroundLayer(sf::Texture& texture)
    : m_Texture(texture)
{
    m_Sprite.setTexture(m_Texture);
}

void BackgroundLayer::update()
{
}

void BackgroundLayer::render(sf::RenderTarget *target)
{
    m_Sprite.setTextureRect(sf::IntRect(0,0,target->getSize().x, target->getSize().y));
    target->draw(m_Sprite);
}