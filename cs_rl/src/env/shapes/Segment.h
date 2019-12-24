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
    // Variables
    const Vec2 m_Source, m_Target;
    const float m_Length;
    const Vec2 m_Direction;
    const Vec2 m_Normal;

    // Functions
    float distanceToPoint(const Vec2& point) const;

public:
    Segment(Vec2 source, Vec2 target);
    ~Segment();
    const float distanceTo(const Shape& other_shape) const override;
    const float distanceToCircle(const Circle& circle) const override;
    const float distanceToSegment(const Segment& segment) const override;
    const float distanceToRaySource(const Ray& ray) const override;

    // Accesors
    const Vec2 getSource() const;
    const Vec2 getTarget() const;

    // Functions
    float normalProjection(const Vec2& point);
    bool intersectsSegment(const Segment& other_segment);
};


#endif // SEGMENT_H