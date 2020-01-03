#include "Entity.h"

// Constructor / Destructor
Entity::~Entity()
{
    delete m_Shape;
}

// Accesors

const Shape* Entity::getShape() const
{
    return m_Shape;
}


