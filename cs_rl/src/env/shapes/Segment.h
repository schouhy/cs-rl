#ifndef SEGMENT_H
#define SEGMENT_H

#include "Shape.h"
#include "Ray.h"
#include "Circle.h"
#include "utils.h"


class Segment : public Shape
{
friend class Environment;
private:
    Vec2 m_Source, m_Target;
    const float m_Length;
    const Vec2 m_Direction;
    const Vec2 m_Normal;
public:
    Segment(Vec2 source, Vec2 target);
    ~Segment();
    const float distanceTo(const Shape& other_shape) const override;
    const float distanceToCircle(const Circle& circle) const ;
    const float distanceToSegment(const Segment& segment) const ;
    const float distanceToRaySource(const Ray& ray) const ;
};


#endif // SEGMENT_H