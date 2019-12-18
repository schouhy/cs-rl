#ifndef RAY_H
#define RAY_H

#include "Shape.h"
#include "utils.h"

class Ray
{
friend class Segment;
friend class Circle;
private:
    const Vec2 m_Source;
    const Vec2 m_Direction, m_Normal;
public:
    Ray(Vec2 source, Vec2 direction);
    ~Ray();
    const float distanceToShape(const Shape& shape) const;
};


#endif // RAY_H