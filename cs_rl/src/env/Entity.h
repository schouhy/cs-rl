#ifndef ENTITY_H
#define ENTITY_H

#include "ShapeManager.h"

class Entity
{
protected:
    Vec2 m_Position;
    Shape *m_Shape;

public:
    // Constructor / Destructor
    Entity(float x, float y);
    virtual ~Entity() = default;

    // Accesors
    virtual const glm::vec2 getPosition() const = 0;
    const Shape* getShape() const;
   // virtual const Shape& getShape() const = 0;
};

#endif