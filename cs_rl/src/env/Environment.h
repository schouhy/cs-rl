#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Player.h"

class Environment
{
private:
    bool m_Done;

    // Players
    std::vector<Player*> m_Players;

    // Walls
    std::vector<Segment*> m_Walls;

    // Initializers
    void initPlayers();
    void initWalls();
    
    // Functions
    void move(const std::vector<ActionInput*>& inputs);
    void collide();
    void shoot(const std::vector<ActionInput*>& inputs);
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