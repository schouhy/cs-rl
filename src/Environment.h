#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Player.h"

class Environment
{
private:
    bool m_Done;
    std::vector<Player*> m_Players;
    //Entity Box;
    
public:
    //Constructor / Destructor
    Environment();
    ~Environment();

    // Accesors
    const std::vector<Player*> getPlayers();

    // Functions
    void step(const std::vector<ActionInput*>& input);
    bool isDone();
};

#endif