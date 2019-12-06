#include "Visualization.h"

// Constructor / Destructor
Visualization::Visualization(Environment *env)
{
    m_Environment = env;
    initPlayerSprites();
}


Visualization::~Visualization()
{
}

// Initializers

void Visualization::initPlayerSprites()
{
    m_PlayerTexture.loadFromFile("src/sprites/rifle/idle/survivor-idle_rifle_1.png");
    m_PlayerSprite.setTexture(m_PlayerTexture);
}

// Functions

void Visualization::update()
{
    updatePlayerAnimation();
}


void Visualization::updatePlayerAnimation()
{
    const Player *player = m_Environment->getPlayer();
    m_PlayerSprite.setPosition(player->getPosition().x, player->getPosition().y);
    m_PlayerSprite.setOrigin(95., 120.);
    m_PlayerSprite.setScale(sf::Vector2f(0.3, 0.3));
    m_PlayerSprite.setRotation(glm::orientedAngle(glm::vec2(1.,0.), glm::normalize(player->getDirection()))*180.f/3.14159f);
}


void Visualization::render(sf::RenderTarget *target)
{
    target->draw(m_PlayerSprite);
}



