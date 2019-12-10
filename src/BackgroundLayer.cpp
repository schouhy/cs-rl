#include "BackgroundLayer.h"


BackgroundLayer::BackgroundLayer(sf::RenderWindow& window, sf::Texture& texture)
    : Layer(window), m_Texture(texture)
{
    m_Sprite.setTexture(m_Texture);
}

void BackgroundLayer::update()
{
}

void BackgroundLayer::render()
{
    m_Sprite.setTextureRect(sf::IntRect(0,0,m_Window.getSize().x, m_Window.getSize().y));
    m_Window.draw(m_Sprite);
}