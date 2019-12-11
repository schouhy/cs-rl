#ifndef ENTITY_H
#define ENTITY_H


#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <vector>

class Entity
{
protected:
    glm::vec2 m_Position;
    float m_Width, m_Height;

public:
    // Constructor / Destructor
    Entity(float x, float y, float h, float w);
    virtual ~Entity() = default;

    // Accesors
    const glm::vec2 getPosition() const;
    const glm::vec2 getTopLeftCorner() const;
    const float getWidth() const;
    const float getHeight() const;
};

#endif