#ifndef UTILS_H
#define UTILS_H


#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/perpendicular.hpp>
#include <vector>
#include <algorithm>


//Debug
#include <iostream>


typedef glm::vec2 Vec2; // Tiene que tener variables publicas .x y .y

Vec2 orthogonal(const Vec2& a);
float determinant(const Vec2& a, const Vec2& b);
Vec2 normalize(const Vec2& a);
float dot(const Vec2& a, const Vec2& b);
float distance(const Vec2& a, const Vec2&b);
float orientedAngle(const Vec2& a, const Vec2& b);
float sqrt(const float& a);
float pow(const float& a, const int& b);
Vec2 rotate(const Vec2& a, const float& angle);

#endif // UTILS_H