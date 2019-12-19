#include "utils.h"

Vec2 orthogonal(const Vec2& a) 
{
    return {-a.y, a.x};
}

float determinant(const Vec2& a, const Vec2& b) 
{
    return a.x*b.y - a.y*b.x;
}

Vec2 normalize(const Vec2& a)
{
    return glm::normalize(a);
}

float dot(const Vec2& a, const Vec2& b)
{
    return glm::dot(a,b);
}

float distance(const Vec2& a, const Vec2& b)
{
    return glm::distance(a,b);
}

float orientedAngle(const Vec2& a, const Vec2& b)
{
    return glm::orientedAngle(a, b);
}

float sqrt(const float& a)
{
    return glm::sqrt(a);
}

float pow(const float& a, const int& b)
{
    return glm::pow(a, b);
}

Vec2 rotate(const Vec2& a, const float& angle)
{
    return glm::rotate(a, angle);
}