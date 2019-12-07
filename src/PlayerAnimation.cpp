#include "PlayerAnimation.h"


// Constructor / Destructor

PlayerAnimation::PlayerAnimation(sf::Sprite& sprite, const Player& player, sf::Texture& texture)
    : m_Sprite(sprite), m_Player(player), m_Texture(texture)
{
    m_Texture.loadFromFile("src/sprites/rifle/idle/survivor-idle_rifle_1.png"); // Despues va a ir en Visualization.cpp
    m_Sprite.setTexture(m_Texture);
}

PlayerAnimation::~PlayerAnimation()
{
}

// Functions

void PlayerAnimation::update()
{
    m_Sprite.setPosition(m_Player.getPosition().x, m_Player.getPosition().y);
    m_Sprite.setOrigin(95., 120.);
    m_Sprite.setScale(sf::Vector2f(0.3, 0.3));
    m_Sprite.setRotation(glm::orientedAngle(glm::vec2(1.,0.), glm::normalize(m_Player.getDirection()))*180.f/3.14159f);
}