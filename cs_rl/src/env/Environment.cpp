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

    for (auto wall : m_Walls)
        delete wall;
}

// Initializers

void Environment::initPlayers()
{
    m_Players.push_back(new Player(400.f, 300.f));
    m_Players.push_back(new Player(500.f, 300.f));
}

void Environment::initWalls()
{
   std::vector<std::vector<Vec2>> walls;
   
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
    walls.push_back(corners);
    walls.push_back({{552, 345},{575, 345},{575, 322}, {552, 322}});
    walls.push_back({{421, 232}, {421, 206}, {390, 206}, {390, 232}});
    walls.push_back({{589, 274}, {600, 249}, {574, 237}, {564, 262}});
    for (auto wall : walls)
        for (std::size_t i=0; i<wall.size(); ++i)
            m_Walls.push_back(new Segment(wall[i], wall[(i+1)%wall.size()]));
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
                Vec2 delta = m_Players[j]->getPosition() - m_Players[i]->getPosition();
                delta = 0.1f*distance*delta;
                m_Players[i]->move(delta);
                // TO-DO: Ver por qué hay que hacer esto y no se puede directamente hacer `Player[j]->move(-1.f*delta);`
                delta = -1.f*delta; 
                m_Players[j]->move(delta);
            }
        }

        // Collision with walls
        for(std::size_t j=0; j<m_Walls.size(); ++j)
        {
            float wall_distance = m_Players[i]->getShape()->distanceTo(*m_Walls[j]);
            if (wall_distance < 0.f)
            {
                Vec2 delta = m_Walls[j]->m_Normal;
                // TO-DO: Ver por qué hay que hacer esto y no se puede directamente hacer `Player[i]->move(-1.f*wall_distance* m_Walls[j]->m_Normal);`
                delta = -1.f*wall_distance*delta; 
                m_Players[i]->move(delta);
            }
        }
    }
}

void Environment::step(const std::vector<ActionInput*>& inputs)
{
    for (std::size_t i=0; i<m_Players.size(); ++i)
        m_Players[i]->move(inputs[i]);
    collide();
}

const bool Environment::isDone() const
{
    return m_Done;
}    
