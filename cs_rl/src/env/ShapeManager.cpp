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

const float Circle::collidesWith(const Shape& other_shape) const
{
    return other_shape.collidesWithCircle(*this);
}

const float Circle::collidesWithCircle(const Circle& circle) const
{
    return std::max<float>(getRadius() + circle.getRadius() - glm::distance(getCenter(), circle.getCenter()), 0.);
}

const float Circle::collidesWithSegment(const Segment& segment) const
{
    return segment.collidesWithCircle(*this);
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


const float Segment::collidesWith(const Shape& other_shape) const
{
    return other_shape.collidesWithSegment(*this);
}

const float Segment::collidesWithCircle(const Circle& circle) const
{
    // Implementar de vuelta
    /*
    float proj_segment = glm::dot(circle.getCenter() - m_Source, m_NormalizedDirection);
    float proj_normal = glm::dot(circle.getCenter() - m_Source, m_NormalizedNormal);

    //std::cout << proj_segment << " " << proj_normal << std::endl;
    if((proj_segment > -circle.getRadius()) && (m_Length + circle.getRadius() > proj_segment))
        if((proj_normal < circle.getRadius()) && (proj_normal > -circle.getRadius()))
            return true;
        else
            return false;
    else
        return false;
    */
   return 0.;
}

const float Segment::collidesWithSegment(const Segment& segment) const
{
    return true; // Implementar
}