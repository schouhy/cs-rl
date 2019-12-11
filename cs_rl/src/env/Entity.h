#ifndef ENTITY_H
#define ENTITY_H


#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <vector>

class Entity
{
protected:
    glm::vec2 m_Position;
 //   const CollisionShape m_CollisionShape;

public:
    // Constructor / Destructor
    Entity(float x, float y);//, const CollisionShape collision_shape);
    virtual ~Entity() = default;

    // Accesors
    const glm::vec2 getPosition() const;
    //virtual const bool checkCollision(const Entity& entity) = 0;
};

#endif