#include "Environment.h"

// Constructor / Destructor
Environment::Environment() 
{
    m_Done = false;
    // Players
    m_Players.push_back(new Player(50.f, 50.f));
    m_Players.push_back(new Player(500.f, 500.f));

    // CollisionBoxTest
    //m_CollisionBoxTest.push_back(new Segment({527.f, 344.f}, {668.f, 344.f}));
    //m_CollisionBoxTest.push_back(new Segment({668.f, 344.f}, {668.f, 215.f}));
    //m_CollisionBoxTest.push_back(new Segment({668.f, 215.f}, {527.f, 215.f}));
    //m_CollisionBoxTest.push_back(new Segment({527.f, 215.f}, {527.f, 344.f}));
}

Environment::~Environment()
{
    // Players
    for (auto player : m_Players)
        delete player;

    // CollisionBoxTest
    //for (auto segment : m_CollisionBoxTest)
    //    delete segment;
}

// Accesors

const std::vector<Player*> Environment::getPlayers() const
{
    return m_Players;
}

// Functions

void Environment::step(const std::vector<ActionInput*>& inputs)
{
    for (std::size_t i=0; i<m_Players.size(); ++i)
        movePlayer(*m_Players[i], inputs[i]);
}

const bool Environment::isDone() const
{
    return m_Done;
}

void Environment::movePlayer(Player& player, ActionInput *input)
{
    player.m_MovementState = input->pos_action;
    float walking_factor = (input->pos_action & Walk)? 0.35 : 1;

    if (player.m_MovementState & StrafeLeft) 
    {
        player.m_Position.x += player.m_Direction.y * 0.5f * walking_factor;
        player.m_Position.y += -player.m_Direction.x * 0.5f * walking_factor;
    }

    if (player.m_MovementState & StrafeRight)
    {
        player.m_Position.x += -player.m_Direction.y * 0.5f * walking_factor;
        player.m_Position.y += player.m_Direction.x * 0.5f * walking_factor;
    }

    if (player.m_MovementState & Forward)
        player.m_Position += player.m_Direction * walking_factor;

    if (player.m_MovementState & Backward)
        player.m_Position -= player.m_Direction * 0.5f * walking_factor;
    player.m_Direction = glm::rotate(player.m_Direction, input->angle_action);
}
    
