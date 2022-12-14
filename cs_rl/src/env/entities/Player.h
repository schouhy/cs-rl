#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "env/Weapon.h"


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
    Vec2 m_Position;
    Vec2 m_lookDirection;
    int m_MovementState;
    float m_DistanceAhead;
    Weapon* m_Weapon;

    // Initializers
    void initShape();

    // Functions
    void move(ActionInput *input);
    void move(Vec2& delta);
public:
    // Constructor / Destructor
    Player(float x, float y);
    ~Player();

    // Functions
    float distanceTo(const Entity& other_entity) override;

    // Accessors
    const Vec2 getPosition() const;
    const Vec2 getDirection() const;
    const int getMovementState() const;
    const float getDistanceAhead() const;
};

#endif // PLAYER_H