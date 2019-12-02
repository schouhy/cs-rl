#include "Visualization.h"

// Constructor / Destructor
Visualization::Visualization(Environment *env)
{
    m_Environment = env;
    const Entity *entity = m_Environment->getEntity();

    m_EntityShape.setPosition(entity->getCenter().first, entity->getCenter().second);
    m_EntityShape.setSize(sf::Vector2f(entity->getHeight(), entity->getWidth()));
    m_EntityShape.setFillColor(sf::Color::Green);
}


Visualization::~Visualization()
{
}

// Functions

void Visualization::update()
{
}

void Visualization::render(sf::RenderTarget *target)
{
    target->draw(m_EntityShape);
}



