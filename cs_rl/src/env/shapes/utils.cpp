#include "utils.h"

Vec2 orthogonal(Vec2 a) 
{
    return {-a.y, a.x};
}

float determinant(Vec2 a, Vec2 b) 
{
    return a.x*b.y - a.y*b.x;
}

Vec2 normalize(Vec2 a)
{
    return glm::normalize(a);
}

float dot(Vec2 a, Vec2 b)
{
    return glm::dot(a,b);
}

float distance(Vec2 a, Vec2 b)
{
    return glm::distance(a,b);
}

float orientedAngle(Vec2 a, Vec2 b)
{
    return glm::orientedAngle(a, b);
}

float sqrt(float a)
{
    return glm::sqrt(a);
}

float pow(float a, int b)
{
    return glm::pow(a, b);
}

Vec2 rotate(Vec2 a, float angle)
{
    return glm::rotate(a, angle);
}