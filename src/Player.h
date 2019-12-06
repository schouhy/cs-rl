#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

#define BIT(x) (1 << x)

enum Action
{
    None  = 0, 
    StrafLeft  = BIT(0), 
    StrafRight = BIT(1), 
    Forward    = BIT(2), 
    Backward  = BIT(3)
};


class Player : public Entity
{
private:
    glm::vec2 m_Direction;
public:
    // Constructor / Destructor
    Player(float x, float y);
    ~Player();

    // Accessors
    const glm::vec2 getDirection() const;


    // Functions
    void performAction(int& action);
};

#endif // PLAYER_H