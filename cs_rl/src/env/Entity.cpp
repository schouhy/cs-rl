#include "Entity.h"


// Constructor / Destructor

Entity::Entity(float x, float y)
    : m_Position({x, y})
{
}

const Shape* Entity::getShape() const
{
    return m_Shape;
}
