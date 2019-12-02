#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "Entity.h"

class Environment
{
private:
    bool m_Done;
    Entity *m_Entity;
    
public:
    Environment();
    ~Environment();

    //Functions
    void step();
    bool isDone() const;
};

#endif