#include "Environment.h"

// Constructor / Destructor
Environment::Environment() 
{
    m_Done = false;
    initPlayers();
    initWalls();
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

// Initializers

void Environment::initPlayers()
{
    m_Players.push_back(new Player(50.f, 50.f));
    m_Players.push_back(new Player(500.f, 500.f));
}

void Environment::initWalls()
{
    // CollisionBoxTest
    m_Walls.push_back(new Segment({527.f, 344.f}, {668.f, 344.f}));
    m_Walls.push_back(new Segment({668.f, 344.f}, {668.f, 215.f}));
    m_Walls.push_back(new Segment({668.f, 215.f}, {527.f, 215.f}));
    m_Walls.push_back(new Segment({527.f, 215.f}, {527.f, 344.f}));
}
// Accesors

const std::vector<Player*> Environment::getPlayers() const
{
    return m_Players;
}

// Functions

void Environment::collide()
{
    for(std::size_t i=0; i<m_Players.size(); ++i)
    {
        for(std::size_t j=i+1; j<m_Players.size(); ++j)
        {
            const float distance = m_Players[i]->getShape()->distanceTo(*m_Players[j]->getShape());
            if (distance < 0.)
            {
                Vec2 collision_direction = m_Players[j]->getPosition() - m_Players[i]->getPosition();
                m_Players[j]->m_Position -= 0.1f*distance*collision_direction;
                m_Players[i]->m_Position += 0.1f*distance*collision_direction;
            }
        }
    }

    float min_wall_distance = m_Players.at(0)->getShape()->distanceTo(*m_Walls.at(0));
    int min_wall_distance_idx = 0;
    for(std::size_t j=1; j<m_Walls.size(); ++j)
    {
        float wall_distance = m_Players[0]->getShape()->distanceTo(*m_Walls[j]);
        if (wall_distance < min_wall_distance)
        {
            min_wall_distance = wall_distance;
            min_wall_distance_idx = j;
        }
    }
    std::cout << min_wall_distance << std::endl;

    if(min_wall_distance < 0.f)
        m_Players[0]->m_Position -= min_wall_distance*(m_Walls[min_wall_distance_idx]->m_NormalizedNormal);

    /*
        const float intersection = m_Players[0]->getShape()->collidesWith(*m_Walls[j]);
        if (intersection > 0.)
        {
            std::cout << j << ") before: " << m_Players.at(0)->m_Position.x << " " << m_Players.at(0)->m_Position.y << std::endl;
            m_Players[0]->m_Position += intersection*(m_Walls[j]->m_NormalizedNormal);
            std::cout << j << ") after: " << m_Players.at(0)->m_Position.x << " " << m_Players.at(0)->m_Position.y << std::endl;
        }
    }*/
}

void Environment::step(const std::vector<ActionInput*>& inputs)
{
    for (std::size_t i=0; i<m_Players.size(); ++i)
        movePlayer(*m_Players[i], inputs[i]);
    collide();
}

const bool Environment::isDone() const
{
    return m_Done;
}

void Environment::movePlayer(Player& player, ActionInput *input)
{
    // m_MovementState
    player.m_MovementState = input->pos_action;

    // m_Direction
    player.m_Direction = glm::rotate(player.m_Direction, input->angle_action);

    // m_Position
    float walking_factor = (input->pos_action & Walk)? 0.45 : 1.3;
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
}
    
