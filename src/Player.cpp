#include "Player.h"

//Constructor / Destructor

Player::Player(float x, float y) : Entity(x, y)
{
}

Player::~Player()
{
}

// Functions

void Player::performAction(int action)
{
    if (action & Left) m_X -= 2.f;
    if (action & Right) m_X += 2.f;
    if (action & Up) m_Y -= 2.f;
    if (action & Down) m_Y += 2.f;
}