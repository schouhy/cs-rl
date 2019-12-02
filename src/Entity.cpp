#include "Entity.h"


// Constructor / Destructor

Entity::Entity()
{
    setPosition(50.f, 50.f, 60.f, 60.f);
}

Entity::~Entity()
{
}

// Accesors

const std::pair<float, float> Entity::getCenter() const
{
    float center_x = (m_BoundingBox.top_left_x + m_BoundingBox.bottom_right_x)/2.f;
    float center_y = (m_BoundingBox.top_left_y + m_BoundingBox.bottom_right_y)/2.f;
    std::pair<float, float> center(center_x, center_y);
    return center;
}

const float Entity::getHeight() const
{
    return m_BoundingBox.bottom_right_y - m_BoundingBox.top_left_y;
}

const float Entity::getWidth() const
{
    return m_BoundingBox.bottom_right_x - m_BoundingBox.top_left_x;
}
// Functions

void Entity::setPosition(float tl_x, float tl_y, float br_x, float br_y)
{
    m_BoundingBox.top_left_x = tl_x;
    m_BoundingBox.top_left_y = tl_y;
    m_BoundingBox.bottom_right_x = br_x;
    m_BoundingBox.bottom_right_y = br_y;
}