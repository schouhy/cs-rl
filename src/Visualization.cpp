#include "Visualization.h"

// Constructor / Destructor
Visualization::Visualization(Environment *env)
{
    m_Environment = env;
    initPlayerSprites();
}


Visualization::~Visualization()
{
    delete m_PlayerAnimation;
}

// Initializers

void Visualization::initPlayerSprites()
{
    m_PlayerAnimation = new PlayerAnimation(m_PlayerSprite, *m_Environment->getPlayer(), m_PlayerTexture);
}

// Functions

void Visualization::update()
{
    updatePlayerAnimation();
}


void Visualization::updatePlayerAnimation()
{
    m_PlayerAnimation->update();
}


void Visualization::render(sf::RenderTarget *target)
{
    target->draw(m_PlayerSprite);
}



