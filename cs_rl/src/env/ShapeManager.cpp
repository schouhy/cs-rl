#include "ShapeManager.h"


glm::vec2 orthogonal(glm::vec2 a) {return {-a.y, a.x};}

// Shape
Shape::Shape()
{
}

Shape::~Shape()
{
}


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


// Segment

Segment::Segment(Vec2 source, Vec2 target) : m_Source(source), m_Target(target) 
{
    m_Length = glm::distance(m_Source, m_Target);
    m_NormalizedDirection = glm::normalize(m_Target - m_Source);
    m_NormalizedNormal = orthogonal(m_NormalizedDirection);
}

Segment::~Segment()
{
}
/*
const Vec2 Segment::getSource() const
{
    return m_Source;
}

const Vec2 Segment::getTarget() const
{
    return m_Target;
}
*/
const float Segment::distToPoint(const Vec2& v) const
{
    return glm::dot(v-m_Source, glm::normalize(orthogonal(m_Target - m_Source)));
}


const float Segment::distanceTo(const Shape& other_shape) const
{
    return other_shape.distanceToSegment(*this);
}

const float Segment::distanceToCircle(const Circle& circle) const
{
    float proj_segment = glm::dot(circle.getCenter() - m_Source, m_NormalizedDirection);
    //float proj_normal = glm::dot(circle.getCenter() - m_Source, m_NormalizedNormal);
    return glm::distance(circle.getCenter(), std::min<float>(m_Length, std::max<float>(0.f, proj_segment))*m_NormalizedDirection + m_Source) - circle.getRadius();
}

const float Segment::distanceToSegment(const Segment& segment) const
{
    return true; // Implementar
}