#include "Player.h"

//Constructor / Destructor

Player::Player(float x, float y) 
    : Entity(x, y), m_lookDirection({1.f, 0.f}), m_MovementState(0), m_Health(100.f)
{
    initShape();
    m_Weapon = new Weapon(75.f, 60);
}

Player::~Player()
{
    delete m_Shape;
    delete m_Weapon;
}

// Functions

void Player::move(ActionInput *input)
{

    // m_MovementState
    m_MovementState = input->pos_action;

    // m_Direction
    m_lookDirection = glm::rotate(m_lookDirection, input->angle_action);

    // m_Position
    float walking_factor = (input->pos_action & Walk)? 0.45 : 1.15;
    //TO-DO: corregir el hecho de que corriendo en diagonal con strafe va más rápido porque se suman las direcciones.
    if (m_MovementState & StrafeLeft) 
    {
        //m_Position += Vec2({m_lookDirection.y, -m_lookDirection.x})* 0.5f * walking_factor;
        m_Position.x += m_lookDirection.y * 0.5f * walking_factor;
        m_Position.y += -m_lookDirection.x * 0.5f * walking_factor;
    }

    if (m_MovementState & StrafeRight)
    {
        //m_Position += Vec2({-m_lookDirection.y, m_lookDirection.x})* 0.5f * walking_factor;
        m_Position.x += -m_lookDirection.y * 0.5f * walking_factor;
        m_Position.y += m_lookDirection.x * 0.5f * walking_factor;
    }

    if (m_MovementState & Forward)
        m_Position += m_lookDirection * walking_factor;

    if (m_MovementState & Backward)
        m_Position -= m_lookDirection * 0.5f * walking_factor;
}

void Player::move(Vec2& delta)
{
    m_Position += delta;
}



// Initializers

void Player::initShape()
{
    m_Shape = new Circle(m_Position, 6.f);
}

// Accessors

const Vec2 Player::getPosition() const
{
    return m_Position;
}

const glm::vec2 Player::getDirection() const
{
    return m_lookDirection;
}

const int Player::getMovementState() const
{
    return m_MovementState;
}
 