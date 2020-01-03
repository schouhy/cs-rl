#ifndef ENTITY_H
#define ENTITY_H

#include "env/shapes/Shapes.h"

class Entity
{
protected:
    Shape *m_Shape;
public:
    // Constructor / Destructor
    Entity() = default;
    virtual ~Entity();

    // Functions
    virtual float distanceTo(const Entity& other_entity) = 0;

    // Accesors
    const Shape* getShape() const;
};

#endif