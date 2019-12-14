#ifndef SHAPES_H
#define SHAPES_H

#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/perpendicular.hpp>
#include <vector>
#include <algorithm>

//Debug
#include <iostream>

typedef glm::vec2 Vec2;

class Circle;
class Segment;

class Shape
{
public:
    Shape();
    virtual ~Shape();
    virtual const bool collidesWith(const Shape& other_shape) const = 0;
    virtual const bool collidesWithCircle(const Circle& circle) const = 0;
    virtual const bool collidesWithSegment(const Segment& segment) const = 0;
};


class Circle : public Shape
{
private:
    Vec2 m_Center;
    float m_Radius;
public:
    Circle(Vec2 center, float radius);
    ~Circle();
    const Vec2 getCenter() const;
    const float getRadius() const;
    const bool collidesWith(const Shape& other_shape) const override;
    const bool collidesWithCircle(const Circle& circle) const override;
    const bool collidesWithSegment(const Segment& segment) const override;

    void setCenter(Vec2 new_center);
};


class Segment : public Shape
{
private:
    Vec2 m_Source, m_Target;
    float m_Length;
    Vec2 m_NormalizedDirection;
    Vec2 m_NormalizedNormal;
public:
    Segment(Vec2 source, Vec2 target);
    ~Segment();
    //const Vec2 getSource() const;
    //const Vec2 getTarget() const;
    const float distToPoint(const Vec2& v) const;
    const bool collidesWith(const Shape& other_shape) const override;
    const bool collidesWithCircle(const Circle& circle) const override;
    const bool collidesWithSegment(const Segment& segment) const override;
};




#endif // SHAPES_H