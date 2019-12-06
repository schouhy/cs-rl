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
    m_EntityShape.setPosition(player->getPosition().x, player->getPosition().y);
    m_EntityShape.setRadius(player->getHeight()); //, player->getWidth()));
    m_EntityShape.setPointCount(3);
    m_EntityShape.setFillColor(sf::Color::Green);

    m_EntityShape.setRotation(glm::orientedAngle(glm::vec2(0.,-1.), glm::normalize(player->getDirection()))*180.f/3.14159f);
}

void Visualization::render(sf::RenderTarget *target)
{
    target->draw(m_EntityShape);
}



