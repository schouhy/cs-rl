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
    m_Players.push_back(new Player(0.4f, 0.4f));
    m_Players.push_back(new Player(0.5f, 0.4f));
    m_Players.push_back(new Player(0.6f, 0.4f));
}

void Environment::initWalls()
{
   std::vector<std::vector<Vec2>> walls;

    /*
    */
   std::vector<Vec2> corners(
    {   
    {0.357422, 0.78776},
    {0.356445, 0.654948},
    {0.369141, 0.652344},
    {0.368164, 0.528646},
    {0.358398, 0.529948},
    {0.358398, 0.488281},
    {0.423828, 0.489583},
    {0.423828, 0.47526},
    {0.408203, 0.472656},
    {0.407227, 0.438802},
    {0.37793, 0.438802},
    {0.378906, 0.167969},
    {0.405273, 0.166667},
    {0.405273, 0.15625},
    {0.423828, 0.154948},
    {0.426758, 0.195312},
    {0.458984, 0.196615},
    {0.456055, 0.236979},
    {0.488281, 0.27474},
    {0.509766, 0.277344},
    {0.506836, 0.476562},
    {0.467773, 0.477865},
    {0.470703, 0.52474},
    {0.50293, 0.528646},
    {0.503906, 0.488281},
    {0.516602, 0.485677},
    {0.516602, 0.277344},
    {0.602539, 0.278646},
    {0.655273, 0.324219},
    {0.654297, 0.348958},
    {0.62793, 0.352865},
    {0.62793, 0.377604},
    {0.600586, 0.380208},
    {0.604492, 0.407552},
    {0.631836, 0.41276},
    {0.652344, 0.407552},
    {0.658203, 0.408854},
    {0.655273, 0.667969},
    {0.638672, 0.669271},
    {0.637695, 0.759115},
    {0.624023, 0.757812},
    {0.571289, 0.832031},
    {0.556641, 0.8125},
    {0.577148, 0.782552},
    {0.59082, 0.78125},
    {0.59082, 0.765625},
    {0.601562, 0.753906},
    {0.592773, 0.744792},
    {0.586914, 0.747396},
    {0.580078, 0.740885},
    {0.572266, 0.753906},
    {0.581055, 0.763021},
    {0.574219, 0.772135},
    {0.567383, 0.765625},
    {0.541016, 0.798177},
    {0.552734, 0.813802},
    {0.541992, 0.829427},
    {0.558594, 0.854167},
    {0.560547, 0.869792},
    {0.548828, 0.871094},
    {0.548828, 0.880208},
    {0.515625, 0.878906},
    {0.515625, 0.811198},
    {0.498047, 0.78776},
    {0.493164, 0.786458},
    {0.492188, 0.761719},
    {0.469727, 0.760417},
    {0.469727, 0.786458},
    {0.446289, 0.789062},
    {0.447266, 0.911458},
    {0.402344, 0.91276},
    {0.402344, 0.78776},
    {0.357422, 0.78776}
    });

    walls.push_back(corners);
    walls.push_back({{0.539062, 0.449219}, {0.561523, 0.449219}, {0.561523, 0.419271}, {0.539062, 0.419271}});
    walls.push_back({{0.411133, 0.302083}, {0.411133, 0.268229}, {0.380859, 0.268229}, {0.380859, 0.302083}});
    walls.push_back({{0.575195, 0.356771}, {0.585938, 0.324219}, {0.560547, 0.308594}, {0.550781, 0.341146}});
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

void Environment::move(const std::vector<ActionInput*>& inputs)
{
    for (std::size_t i=0; i<m_Players.size(); ++i)
        m_Players[i]->move(inputs[i]);
}


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
                Vec2 delta = normalize(m_Players[j]->getPosition() - m_Players[i]->getPosition());
                delta = distance*delta;
                m_Players[i]->move(delta);
                // TO-DO: Ver por qué hay que hacer esto y no se puede 
                // directamente hacer `Player[j]->move(-1.f*delta);`
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
                // TO-DO: Ver por qué hay que hacer esto y no se puede 
                // directamente hacer `Player[i]->move(-1.f*wall_distance* m_Walls[j]->m_Normal);`
                delta = -1.f*wall_distance*delta; 
                m_Players[i]->move(delta);
            }
        }
    }
}

void Environment::updatePlayerDistanceAhead()
{
    for(auto player: m_Players)
    {
        Ray ray(player->getPosition(), player->getDirection());
        // Walls
        // TO-DO: Mejorar esto, arrancar con mi_wall_distance=1e8f está feo (?).
        float min_wall_distance = 1e3f;
        for(auto wall : m_Walls)
        {
            float new_distance = ray.distanceToShape(*wall);
            if (new_distance > 0.f && new_distance < min_wall_distance)
                min_wall_distance = new_distance;        
        }
        player->m_DistanceAhead = min_wall_distance;
    }
}


void Environment::combat(const std::vector<ActionInput*>& inputs)
{
    for (std::size_t i=0; i<m_Players.size(); ++i)
    {
        if (inputs[i]->pos_action & Action::Shoot && m_Players[i]->m_Weapon->isReady())
            fire(m_Players[i]);
        else
            m_Players[i]->m_Weapon->update();
    }

}

void Environment::fire(Player* player)
{
    player->m_Weapon->fire();
    Ray shot(player->getPosition(), player->getDirection());
    
    std::cout << player->m_DistanceAhead << std::endl;
    // Other players
    for (auto other_player : m_Players)
    {
        if(player != other_player)
        {
            float distance_to_other_player = shot.distanceToShape(*other_player->getShape());
            if ((distance_to_other_player >= 0.f) && (distance_to_other_player < player->getDistanceAhead()))
                std::cout << "HIT" << std::endl;
            else
                std::cout << "MISS" << std::endl;
        }
    }
    std::cout << "###" << std::endl;
   
}


void Environment::step(const std::vector<ActionInput*>& inputs)
{
    move(inputs);
    collide();
    updatePlayerDistanceAhead();
    combat(inputs);
}

const bool Environment::isDone() const
{
    return m_Done;
}    
