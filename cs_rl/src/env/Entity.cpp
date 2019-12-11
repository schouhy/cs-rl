#include "Entity.h"


// Constructor / Destructor

Entity::Entity(float x, float y)//, const CollisionShape collision_shape) 
    : m_Position({x, y}) //, m_CollisionShape(collision_shape)
{
}


// Accesors

const glm::vec2 Entity::getPosition() const
{
    return m_Position;
}
