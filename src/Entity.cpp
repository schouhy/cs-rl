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

const std::pair<float, float> Entity::getPosition() const
{
    return {m_X, m_Y};
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
    m_X = x;
    m_Y = y;
}