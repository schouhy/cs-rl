#include "Environment.h"

// Constructor / Destructor
Environment::Environment() 
{
    m_Done = false;
    m_Players.push_back(new Player(50.f, 50.f));
    m_Players.push_back(new Player(500.f, 500.f));
}

Environment::~Environment()
{
    for (auto player : m_Players)
        delete player;
}

// Accesors

const std::vector<Player*> Environment::getPlayers()
{
    return m_Players;
}

// Functions

void Environment::step(const std::vector<ActionInput*>& inputs)
{
    m_Players.at(0)->performAction(inputs.at(0));
    m_Players.at(1)->performAction(inputs.at(1));
}

bool Environment::isDone()
{
    return m_Done;
}