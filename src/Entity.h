#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <chrono>
#include "SFML/Graphics.hpp"


class Entity
{
public:
    // Constructor / Destructor
    Entity();
    virtual ~Entity();

    // Accesors
    const std::pair<float, float> getCenter() const;
    const float getWidth() const;
    const float getHeight() const;

    // Functions
    void setPosition(float tl_x, float tl_y, float br_x, float br_y);

private:
    struct BoundingBox
    {
        float top_left_x;
        float top_left_y;
        float bottom_right_x;
        float bottom_right_y;
    };

    BoundingBox m_BoundingBox;
};

#endif