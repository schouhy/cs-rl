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
private:
    Vec2 m_Direction;
    int m_MovementState;

    // Initializers
    void initShape();
public:
    // Constructor / Destructor
    Player(float x, float y);
    ~Player();

    const Vec2 getPosition() const;

    // Accessors
    const Vec2 getDirection() const;
    const int getMovementState() const;

    // Functions
    void performAction(ActionInput *input);
};

#endif // PLAYER_H