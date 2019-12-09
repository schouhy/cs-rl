#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Player.h"

class Environment
{
private:
    bool m_Done;
    std::vector<Player*> m_Players;
    
public:
    //Constructor / Destructor
    Environment();
    ~Environment();

    // Accesors
    const std::vector<Player*> getPlayers();
    // Functions
    void step(int& pos_action, float& angle_action);
    bool isDone();
};

#endif