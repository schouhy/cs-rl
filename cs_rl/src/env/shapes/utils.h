#ifndef UTILS_H
#define UTILS_H


#include <glm/glm.hpp>
#include <glm/gtx/vector_angle.hpp>
#include <glm/gtx/perpendicular.hpp>
#include <vector>
#include <algorithm>

//Debug
#include <iostream>


typedef glm::vec2 Vec2;

glm::vec2 orthogonal(glm::vec2 a);
float determinant(glm::vec2 a, glm::vec2 b);

#endif // UTILS_H