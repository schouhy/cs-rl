#include "Wall.h"


// Constructor / Destructor
Wall::Wall(Vec2 start, Vec2 end)
{
    initShape(start, end);
}

// Functions

const Vec2 Wall::getNormal()
{
    return static_cast<Segment*>(m_Shape)->m_Normal;
}

void Wall::initShape(Vec2 start, Vec2 end)
{
    m_Shape = new Segment(start, end);
}

float Wall::distanceTo(const Entity& other_entity)
{
    return other_entity.getShape()->distanceToSegment(*static_cast<Segment*>(m_Shape));
}
