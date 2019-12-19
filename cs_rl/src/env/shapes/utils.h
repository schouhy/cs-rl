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

Vec2 orthogonal(Vec2 a);
float determinant(Vec2 a, Vec2 b);
Vec2 normalize(Vec2 a);
float dot(Vec2 a, Vec2 b);
float distance(Vec2 a, Vec2 b);
float orientedAngle(Vec2 a, Vec2 b);
float sqrt(float a);
float pow(float a, int b);
Vec2 rotate(Vec2 a, float angle);

#endif // UTILS_H