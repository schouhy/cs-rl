#include "Player.h"

//Constructor / Destructor

Player::Player(float x, float y) : Entity(x, y)
{

    m_Direction.x = 1.f;
    m_Direction.y = 0.f;
}

Player::~Player()
{
}

// Accessors

const glm::vec2 Player::getDirection() const
{
    return m_Direction;
}


// Functions

void Player::performAction(int& pos_action, float& angle_action)
{
    float walking_factor = (pos_action & Walk)? 0.35 : 1;

    if (pos_action & StrafLeft) 
    {
        m_Position.x += m_Direction.y * 0.7f * walking_factor;
        m_Position.y += -m_Direction.x * 0.7f * walking_factor;
    }
    if (pos_action & StrafRight)
    {
        m_Position.x += -m_Direction.y * 0.7f * walking_factor;
        m_Position.y += m_Direction.x * 0.7f * walking_factor;
    }
    if (pos_action & Forward)
        m_Position += m_Direction * walking_factor;
    if (pos_action & Backward)
        m_Position -= m_Direction * 0.5f * walking_factor;
    m_Direction = glm::rotate(m_Direction, angle_action);
}
 