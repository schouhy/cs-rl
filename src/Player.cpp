#include "Player.h"

//Constructor / Destructor

Player::Player(float x, float y) : Entity(x, y)
{
}

Player::~Player()
{
}

// Functions

void Player::performAction(Action action)
{
    switch(action)
    {
        case Left:
            m_X -= 5.f;
            break;
        case Right:
            m_X += 5.f;
            break;
        case Up:
            m_Y -= 5.f;
            break;
        case Down:
            m_Y += 5.f;
            break;
    }

}