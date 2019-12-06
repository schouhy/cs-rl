#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

#define BIT(x) (1 << x)

enum Action
{
    None  = 0, 
    Left  = BIT(0), 
    Right = BIT(1), 
    Up    = BIT(2), 
    Down  = BIT(3)
};

class Player : public Entity
{
public:
    // Constructor / Destructor
    Player(float x, float y);
    ~Player();

    // Functions
    void performAction(int action);
};

#endif // PLAYER_H