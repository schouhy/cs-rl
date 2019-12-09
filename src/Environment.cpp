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

void Environment::step(int& pos_action, float& angle_action)
{
    m_Players.at(0)->performAction(pos_action, angle_action);
}

bool Environment::isDone()
{
    return m_Done;
}