#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "entities/Player.h"
#include "env/shapes/ShapesManager.h"


class Environment
{
private:
    bool m_Done;

    // Players
    std::vector<Player*> m_Players;
    // Walls
    std::vector<Segment*> m_Walls;
    ShapesManager *m_ShapesManager;

    // Initializers
    void initPlayers();
    void initWalls();
    
    // Functions
    void move(const std::vector<ActionInput*>& inputs);
    void collide();
    void updatePlayerDistanceAhead();
    void combat(const std::vector<ActionInput*>& inputs);
    void fire(Player* player);
public:
    //Constructor / Destructor
    Environment();
    ~Environment();

    // Accesors
    const std::vector<Player*> getPlayers() const;

    // Functions
    void step(const std::vector<ActionInput*>& input);
    const bool isDone() const;
};

#endif