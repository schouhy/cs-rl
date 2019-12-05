#include "Player.h"

//Constructor / Destructor

Player::Player(float x, float y) : Entity(x, y)
{
}

Player::~Player()
{
}

// Functions
/*
void Player::performAction(Action action)
{
    switch(action)
    {
        case Left:
            std::cout << "sasa" << std::endl;
            m_X -= 5.f;
        case Right:
            m_X += 5.f;
        case Up:
            m_Y -= 5.f;
        case Down:
            m_Y += 5.f;
    }

}*/