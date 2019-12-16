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
    m_Players.push_back(new Player(400.f, 300.f));
    m_Players.push_back(new Player(500.f, 300.f));
}

void Environment::initWalls()
/*
    m_Walls.push_back(new Segment({527.f, 344.f}, {668.f, 344.f}));
    m_Walls.push_back(new Segment({668.f, 344.f}, {668.f, 215.f}));
    m_Walls.push_back(new Segment({668.f, 215.f}, {527.f, 215.f}));
    m_Walls.push_back(new Segment({527.f, 215.f}, {527.f, 344.f}));
*/

{
   /* std::vector<Vec2> corners({{527.f, 344.f}, 
                              {668.f, 344.f}, 
                              {668.f, 215.f}, 
                              {527.f, 215.f}});
    */
   std::vector<Vec2> corners(
    {{366, 605},
    {412, 605},
    {412, 701},
    {458, 700},
    {457, 606},
    {481, 604},
    {481, 584},
    {504, 585},
    {505, 604},
    {510, 605},
    {528, 623},
    {528, 675},
    {562, 676},
    {562, 669},
    {574, 668},
    {572, 656},
    {555, 637},
    {566, 625},
    {554, 613},
    {581, 588},
    {588, 593},
    {595, 586},
    {586, 579},
    {594, 569},
    {601, 574},
    {607, 572},
    {616, 579},
    {605, 588},
    {605, 600},
    {591, 601},
    {570, 624},
    {585, 639},
    {639, 582},
    {653, 583},
    {654, 514},
    {671, 513},
    {674, 314},
    {668, 313},
    {647, 317},
    {619, 313},
    {615, 292},
    {643, 290},
    {643, 271},
    {670, 268},
    {671, 249},
    {617, 214},
    {529, 213},
    {529, 373},
    {516, 375},
    {515, 406},
    {482, 403},
    {479, 367},
    {519, 366},
    {522, 213},
    {500, 211},
    {467, 182},
    {470, 151},
    {437, 150},
    {434, 119},
    {415, 120},
    {415, 128},
    {388, 129},
    {387, 337},
    {417, 337},
    {418, 363},
    {434, 365},
    {434, 376},
    {367, 375},
    {367, 407},
    {377, 406},
    {378, 501},
    {365, 503},
    {366, 605}});

    std::reverse(corners.begin(), corners.end());
    for (std::size_t i=0; i<corners.size(); ++i)
    {
        m_Walls.push_back(new Segment(corners[i], corners[(i+1)%corners.size()]));
    }
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
        // Collision with other players
        for(std::size_t j=i+1; j<m_Players.size(); ++j)
        {
            const float distance = m_Players[i]->getShape()->distanceTo(*m_Players[j]->getShape());
            if (distance < 0.)
            {
                Vec2 collision_direction = m_Players[j]->m_Position - m_Players[i]->m_Position;
                m_Players[j]->m_Position -= 0.1f*distance*collision_direction;
                m_Players[i]->m_Position += 0.1f*distance*collision_direction;
            }
        }
        // Collision with walls
            for(std::size_t j=0; j<m_Walls.size(); ++j)
            {
                float wall_distance = m_Players[i]->getShape()->distanceTo(*m_Walls[j]);
                if (wall_distance < 0.f)
                {
                    const Vec2& bounce_dir = m_Walls[j]->m_NormalizedNormal;
                    m_Players[i]->m_Position -= wall_distance*bounce_dir;
                }
            }
    }
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
    player.m_lookDirection = glm::rotate(player.m_lookDirection, input->angle_action);

    // m_Position
    player.m_Velocity = player.m_Position;
    float walking_factor = (input->pos_action & Walk)? 0.45 : 1.3;
    if (player.m_MovementState & StrafeLeft) 
    {
        player.m_Position.x += player.m_lookDirection.y * 0.5f * walking_factor;
        player.m_Position.y += -player.m_lookDirection.x * 0.5f * walking_factor;
    }

    if (player.m_MovementState & StrafeRight)
    {
        player.m_Position.x += -player.m_lookDirection.y * 0.5f * walking_factor;
        player.m_Position.y += player.m_lookDirection.x * 0.5f * walking_factor;
    }

    if (player.m_MovementState & Forward)
        player.m_Position += player.m_lookDirection * walking_factor;

    if (player.m_MovementState & Backward)
        player.m_Position -= player.m_lookDirection * 0.5f * walking_factor;
    player.m_Velocity = player.m_Position - player.m_Velocity;
}
    
