#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"
#include "Ray.h"
#include "Segment.h"
#include "utils.h"


class Circle : public Shape
{
private:
    Vec2& m_Center;
    const float m_Radius;
public:
    Circle(Vec2& center, float radius);
    ~Circle();
    const Vec2 getCenter() const;
    const float getRadius() const;
    const float distanceTo(const Shape& other_shape) const override;
    const float distanceToCircle(const Circle& circle) const override;
    const float distanceToSegment(const Segment& segment) const override;
    const float distanceToRaySource(const Ray& ray) const override; // borrar
};

#endif // CIRCLE_H