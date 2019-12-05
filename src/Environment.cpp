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

void Environment::step(Action action)
{
    m_Player->performAction(action);
}

bool Environment::isDone() const
{
    return m_Done;
}