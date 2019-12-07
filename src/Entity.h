#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <chrono>
#include <experimental/filesystem>
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>

#define TIME_PER_FRAME 1.f/60.f
#define MOUSEPOSITION 200


class Entity
{
protected:
    glm::vec2 m_Position;
    float m_Width, m_Height;
public:
    // Constructor / Destructor
    Entity(float x, float y);
    virtual ~Entity();

    // Accesors
    const glm::vec2 getPosition() const;
    const float getWidth() const;
    const float getHeight() const;

    // Functions
    void setPosition(float x, float y);
};

#endif