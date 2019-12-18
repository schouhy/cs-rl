#include "utils.h"

glm::vec2 orthogonal(glm::vec2 a) 
{
    return {-a.y, a.x};
}

float determinant(glm::vec2 a, glm::vec2 b) 
{
    return a.x*b.y - a.y*b.x;
}