#include "Segment.h"



Segment::Segment(Vec2 source, Vec2 target) 
    : m_Source(source), m_Target(target),
    m_Length(distance(m_Source, m_Target)),
    m_Direction(normalize(m_Target - m_Source)),
    m_Normal(orthogonal(m_Direction))
{
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
    float proj_normal_coeff = dot(circle.getCenter() - m_Source, m_Normal);
    if(proj_normal_coeff < 0.)
        return 10.f;
    else
    {
        float seg_dir_coeff = dot(circle.getCenter() - m_Source, m_Direction);
        seg_dir_coeff = std::min<float>(m_Length, std::max<float>(0.f, seg_dir_coeff));
        Vec2 proj_seg_dir = seg_dir_coeff*m_Direction + m_Source;
        return distance(circle.getCenter(), proj_seg_dir) - circle.getRadius();
    }
}

const float Segment::distanceToSegment(const Segment& segment) const
{
    // Implementar
}

const float Segment::distanceToRaySource(const Ray& ray) const
{
    // Checks whether ray crosses Segment
    if (dot(ray.m_Normal, m_Source - ray.m_Source) * dot(ray.m_Normal, m_Target - ray.m_Source) > 0)
        return -1.f;
    else
    {
        // Cramer's rule to solve dist_d*ray_Direction - dist_s*m_Direction = m_Source - ray_Source
        float dist_d = determinant(m_Direction, m_Source - ray.m_Source) / (determinant(m_Direction, ray.m_Direction));
        float dist_s = -determinant(m_Source - ray.m_Source, ray.m_Direction) / (determinant(m_Direction, ray.m_Direction));

        if(dist_d >= 0.f)
            return dist_d;
        else
            return -1.f;
    }
}
