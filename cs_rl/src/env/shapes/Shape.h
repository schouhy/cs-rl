#ifndef SHAPE_H
#define SHAPE_H


#include "utils.h"

class Circle;
class Segment;
class Ray;

class Shape
{
public:
    Shape();
    virtual ~Shape();
    virtual const float distanceTo(const Shape& other_shape) const = 0;
    virtual const float distanceToCircle(const Circle& circle) const = 0;
    virtual const float distanceToSegment(const Segment& segment) const = 0;
    virtual const float distanceToRaySource(const Ray& ray) const = 0; // borrar
};

#endif // SHAPE_H