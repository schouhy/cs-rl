#include "ShapeManager.h"


glm::vec2 orthogonal(glm::vec2 a) {return {-a.y, a.x};}
float determinant(glm::vec2 a, glm::vec2 b) {return a.x*b.y - a.y*b.x;}


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

const float Circle::isHittedBy(const Ray& ray) const
{
    // Returns -1.f if is not hitted by ray. If it is hitted, it returns the distance to it.
    float center_normal_distance = std::abs(glm::dot(m_Center - ray.getSource(), ray.getNormal()));
    if (center_normal_distance > m_Radius)
        return -1.f;
    else
    {
        float center_distance = glm::dot(m_Center - ray.getSource(), ray.getDirection());
        return center_distance - (glm::sqrt(glm::pow(m_Radius, 2) - glm::pow(center_normal_distance, 2)));
    }
}


// Segment

Segment::Segment(Vec2 source, Vec2 target) : m_Source(source), m_Target(target) 
{
    m_Length = glm::distance(m_Source, m_Target);
    m_Direction = glm::normalize(m_Target - m_Source);
    m_Normal = orthogonal(m_Direction);
}

Segment::~Segment()
{
}


const float Segment::distanceTo(const Shape& other_shape) const
{
    return other_shape.distanceToSegment(*this);
}

const float Segment::distanceToCircle(const Circle& circle) const
{
    float proj_normal_coeff = glm::dot(circle.getCenter() - m_Source, m_Normal);
    if(proj_normal_coeff < 0.)
        return 10.f;
    else
    {
        float seg_dir_coeff = glm::dot(circle.getCenter() - m_Source, m_Direction);
        seg_dir_coeff = std::min<float>(m_Length, std::max<float>(0.f, seg_dir_coeff));
        Vec2 proj_seg_dir = seg_dir_coeff*m_Direction + m_Source;
        return glm::distance(circle.getCenter(), proj_seg_dir) - circle.getRadius();
    }
}

const float Segment::distanceToSegment(const Segment& segment) const
{
    // Implementar
}

const float Segment::isHittedBy(const Ray& ray) const
{
    float dist_d = determinant(m_Source - ray.getSource(), m_Direction) / (determinant(ray.getDirection(), m_Direction));
    float dist_s = determinant(ray.getSource() - m_Source, ray.getDirection()) / (determinant(m_Direction, ray.getDirection()));
    if(dist_s >= 0.f && dist_s <= m_Length && dist_d >= 0.f)
        return dist_d;
    else
        return -1.f;
}


// Ray

Ray::Ray(Vec2 source, Vec2 direction)
    : m_Source(source)
{
    m_Direction = glm::normalize(direction);
    m_Normal = orthogonal(m_Direction);
}

Ray::~Ray()
{
}

const float Ray::hits(const Shape& shape) const
{
    return shape.isHittedBy(*this);
}

const Vec2 Ray::getSource() const
{
    return m_Source;
}
const Vec2 Ray::getDirection() const
{
    return m_Direction;
}

const Vec2 Ray::getNormal() const
{
    return m_Normal;
}
