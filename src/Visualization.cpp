#include "Visualization.h"

// Constructor / Destructor
Visualization::Visualization(Environment *env)
{
    m_Environment = env;
}


Visualization::~Visualization()
{
}

// Functions

void Visualization::update()
{
    const Player *player = m_Environment->getPlayer();
    m_EntityShape.setPosition(player->getPosition().first, player->getPosition().second);
    m_EntityShape.setSize(sf::Vector2f(player->getHeight(), player->getWidth()));
    m_EntityShape.setFillColor(sf::Color::Green); 
}

void Visualization::render(sf::RenderTarget *target)
{
    target->draw(m_EntityShape);
}



