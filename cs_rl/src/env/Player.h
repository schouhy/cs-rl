#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

#define BIT(x) (1 << x)

enum Action
{
    Idle  = 0, 
    StrafeLeft  = BIT(0), 
    StrafeRight = BIT(1), 
    Forward     = BIT(2), 
    Backward    = BIT(3),
    Walk        = BIT(4),
    Shoot       = BIT(5)
};

struct ActionInput
{
    int pos_action = 0;
    float angle_action = 0.f;
};


class Player : public Entity
{
friend class Environment;
private:
    Vec2 m_BoundingCirclePosition;
    Vec2 m_lookDirection;
    int m_MovementState;
 
    // Initializers
    void initShape();

    // Functions
    void move(ActionInput *input);
public:
    // Constructor / Destructor
    Player(float x, float y);
    ~Player();

    // Accessors
    const Vec2 getPosition() const;
    const Vec2 getDirection() const;
    const int getMovementState() const;
};

#endif // PLAYER_H