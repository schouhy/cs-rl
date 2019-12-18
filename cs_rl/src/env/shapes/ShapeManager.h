#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/perpendicular.hpp>
#include <vector>
#include <algorithm>

//Debug
#include <iostream>

#define BC_OFFSET_FACTOR 3.5f


typedef glm::vec2 Vec2;

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
    virtual const float isHittedBy(const Ray& ray) const = 0;
};


class Circle : public Shape
{
private:
    Vec2& m_Center;
    float m_Radius;
public:
    Circle(Vec2& center, float radius);
    ~Circle();
    const Vec2 getCenter() const;
    const float getRadius() const;
    const float distanceTo(const Shape& other_shape) const override;
    const float distanceToCircle(const Circle& circle) const override;
    const float distanceToSegment(const Segment& segment) const override;
    const float isHittedBy(const Ray& ray) const override;
};


class Segment : public Shape
{
friend class Environment;
private:
    Vec2 m_Source, m_Target;
    float m_Length;
    Vec2 m_Direction;
    Vec2 m_Normal;
public:
    Segment(Vec2 source, Vec2 target);
    ~Segment();
    const float distanceTo(const Shape& other_shape) const override;
    const float distanceToCircle(const Circle& circle) const override;
    const float distanceToSegment(const Segment& segment) const override;
    const float isHittedBy(const Ray& ray) const override;
};


class Ray
{
private:
    Vec2 m_Source;
    Vec2 m_Direction, m_Normal;
public:
    Ray(Vec2 source, Vec2 direction);
    ~Ray();
    const float hits(const Shape& shape) const;
    const Vec2 getSource() const;
    const Vec2 getDirection() const;
    const Vec2 getNormal() const;
};



#endif // SHAPES_H