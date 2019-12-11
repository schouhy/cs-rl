#include "Entity.h"


// Constructor / Destructor

Entity::Entity(float x, float y, float h, float w) 
    : m_Position({x, y}), m_Height(h), m_Width(w)
{
}


// Accesors

const glm::vec2 Entity::getPosition() const
{
    return m_Position;
}

const glm::vec2 Entity::getTopLeftCorner() const
{
    return {m_Position.x - m_Width/2.f, m_Position.y - m_Height/2.f};
}

const float Entity::getHeight() const
{
    return m_Height;
}

const float Entity::getWidth() const
{
    return m_Width;
}