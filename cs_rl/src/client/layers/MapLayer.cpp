#include "MapLayer.h"


MapLayer::MapLayer(sf::RenderWindow& window, sf::Texture& texture)
    : Layer(window), m_Texture(texture)
{
    sf::Vector2u texture_size = m_Texture.getSize();
    sf::Vector2u window_size = window.getSize();
    float xscale = (float) window_size.x / texture_size.x;
    float yscale = (float) window_size.y / texture_size.y;

    m_Sprite.setTexture(m_Texture);
    m_Sprite.setScale(xscale, yscale);
}

void MapLayer::update()
{
}

void MapLayer::render()
{
    //m_Sprite.setTextureRect(sf::IntRect(0,0,m_Window.getSize().x, m_Window.getSize().y));
    m_Window.draw(m_Sprite);
}

