#include "PlayerVisualization.h"


// Constructor / Destructor

PlayerVisualization::PlayerVisualization(
    const Player& player, 
    textures_map& body_textures, 
    textures_map& feet_textures)
    : m_BodyTextures(body_textures), m_FeetTextures(feet_textures)
{
    m_Layers.push_back(new PlayerAnimation(player, m_BodySprite, m_BodyTextures));
    m_Layers.push_back(new PlayerAnimation(player, m_FeetSprite, m_FeetTextures));
}

// Functions

/*
void PlayerVisualization::update()
{
    m_BodyAnimation->update();
    m_FeetAnimation->update();
    
    // Transformations
    //m_BodySprite.setPosition(m_Player.getPosition().x, m_Player.getPosition().y);
    m_BodySprite.setOrigin(95., 120.);
    m_BodySprite.setScale(sf::Vector2f(0.4, 0.4));
    m_BodySprite.setRotation(glm::orientedAngle(glm::vec2(1.,0.), glm::normalize(m_Player.getDirection()))*180.f/3.14159f);

    m_FeetSprite.setPosition(300., 300.);//m_Player.getPosition().x, m_Player.getPosition().y);
    //m_FeetSprite.setOrigin(95., 120.);
    //m_FeetSprite.setScale(sf::Vector2f(0.4, 0.4));
    //m_FeetSprite.setRotation(glm::orientedAngle(glm::vec2(1.,0.), glm::normalize(m_Player.getDirection()))*180.f/3.14159f);
}

void PlayerVisualization::render(sf::RenderTarget *target)
{
    target->draw(m_FeetAnimation->getSprite());
    //target->draw(m_BodyAnimation->getSprite());
}*/