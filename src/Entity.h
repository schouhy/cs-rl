#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <chrono>
#include "SFML/Graphics.hpp"


class Entity
{
protected:
    float m_X, m_Y;
    float m_Width, m_Height;
public:
    // Constructor / Destructor
    Entity(float x, float y);
    virtual ~Entity();

    // Accesors
    const std::pair<float, float> getPosition() const;
    const float getWidth() const;
    const float getHeight() const;

    // Functions
    void setPosition(float x, float y);
};

#endif