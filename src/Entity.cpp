#include "Entity.h"


// Constructor / Destructor

Entity::Entity(float x, float y)
{
    setPosition(50.f, 50.f);
    m_Height = 10.f;
    m_Width = 10.f;
}

Entity::~Entity()
{
}

// Accesors

const glm::vec2 Entity::getPosition() const
{
    return m_Position;
}

const float Entity::getHeight() const
{
    return m_Height;
}

const float Entity::getWidth() const
{
    return m_Width;
}
// Functions

void Entity::setPosition(float x, float y)
{
    m_Position.x = x;
    m_Position.y = y;
}