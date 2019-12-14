#include "Player.h"

//Constructor / Destructor

Player::Player(float x, float y) 
    : Entity(x, y), m_Direction({1.3f, 0.f}), m_MovementState(0)
{
    initShape();
}

Player::~Player()
{
    delete m_Shape;
}

const Vec2 Player::getPosition() const
{
    return m_Position;
}

// Initializers

void Player::initShape()
{
    m_Shape = new Circle(m_Position, 10.f);
   // m_Shape = static_cast<Circle*>(m_Shape);
}

// Accessors

const glm::vec2 Player::getDirection() const
{
    return m_Direction;
}

const int Player::getMovementState() const
{
    return m_MovementState;
}
 