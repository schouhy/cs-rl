#include "Player.h"

//Constructor / Destructor

Player::Player(float x, float y) : Entity(x, y)
{

    m_Direction.x = 0.f;
    m_Direction.y = -1.f;
}

Player::~Player()
{
}

// Functions

void Player::performAction(int& action)
{
    if (action & StrafLeft) 
    {
        m_Position.x += m_Direction.y * 0.7f;
        m_Position.y += -m_Direction.x * 0.7f;
    }
    if (action & StrafRight)
    {
        m_Position.x += -m_Direction.y * 0.7f;
        m_Position.y += m_Direction.x * 0.7f;
    }
    if (action & Forward)
    {
        m_Position += m_Direction;
    }
    if (action & Backward)
    {
        m_Position -= m_Direction * 0.5f;
    }
}
