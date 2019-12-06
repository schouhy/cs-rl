#include "Environment.h"

// Constructor / Destructor
Environment::Environment() 
{
    m_Done = false;
    m_Player = new Player(50.f, 50.f);
}

Environment::~Environment()
{
    delete m_Player;
}

// Accesors

const Player * const Environment::getPlayer() const 
{
    return m_Player;
}

// Functions

void Environment::step(int& pos_action, float& angle_action)
{
    m_Player->performAction(pos_action, angle_action);
}

bool Environment::isDone() const
{
    return m_Done;
}