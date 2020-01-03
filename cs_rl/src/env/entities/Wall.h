#ifndef WALL_H
#define WALL_H

#include "Entity.h"

class Wall : public Entity
{
friend class Environment; // Borrar
private:
    // Functions
    void initShape(Vec2 start, Vec2 end);
    const Vec2 getNormal();
public:
    // Constructor / Destructor
    Wall(Vec2 start, Vec2 end);
    ~Wall() = default;

    // Functions
    float distanceTo(const Entity& other_entity) override;
};


#endif // WALL_H