#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Player.h"

class Environment
{
private:
    bool m_Done;
    Player *m_Player;
    
public:
    //Constructor / Destructor
    Environment();
    ~Environment();

    // Accesors
    const Player * const getPlayer() const;
    // Functions
    void step(int& pos_action, float& angle_action);
    bool isDone() const;
};

#endif