#include "Entity.h"


// Constructor / Destructor

Entity::Entity(float x, float y) 
    : m_Position({x, y}), m_Height(15.f), m_Width(15.f)
{
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