#include "Ray.h"



Ray::Ray(Vec2 source, Vec2 direction)
    : m_Source(source), m_Direction(glm::normalize(direction)),
    m_Normal(orthogonal(m_Direction))
{
}

Ray::~Ray()
{
}

const float Ray::distanceToShape(const Shape& shape) const
{
    return shape.distanceToRaySource(*this);
}
