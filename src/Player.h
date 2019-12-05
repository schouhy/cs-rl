#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

enum Action
{
    None=0, Left, Right, Up, Down
};

class Player : public Entity
{
public:
    // Constructor / Destructor
    Player(float x, float y);
    ~Player();

    // Functions
    void performAction(Action action);
};

#endif // PLAYER_H