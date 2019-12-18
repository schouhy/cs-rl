#include "Circle.h"

// Circle

Circle::Circle(Vec2& center, float radius) : m_Radius(radius), m_Center(center) 
{
}

Circle::~Circle()
{
}

const Vec2 Circle::getCenter() const
{
    return m_Center;
}

const float Circle::getRadius() const
{
    return m_Radius;
}

/*
void Circle::setCenter(Vec2 new_center)
{
    m_Center = new_center;
}*/

const float Circle::distanceTo(const Shape& other_shape) const
{
    return other_shape.distanceToCircle(*this);
}

const float Circle::distanceToCircle(const Circle& circle) const
{
    return glm::distance(getCenter(), circle.getCenter()) - getRadius() - circle.getRadius();
}

const float Circle::distanceToSegment(const Segment& segment) const
{
    return segment.distanceToCircle(*this);
}

const float Circle::distanceToRaySource(const Ray& ray) const
{
    // Returns -1.f if is not hitted by ray. If it is hitted, it returns the distance to it.
    float center_normal_distance = std::abs(glm::dot(m_Center - ray.m_Source, ray.m_Normal));
    if (center_normal_distance > m_Radius)
        return -1.f;
    else
    {
        float center_distance = glm::dot(m_Center - ray.m_Source, ray.m_Direction);
        return center_distance - (glm::sqrt(glm::pow(m_Radius, 2) - glm::pow(center_normal_distance, 2)));
    }
}

