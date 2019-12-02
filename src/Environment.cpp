#include "Environment.h"


Environment::Environment() 
{
    m_Done = false;
}

Environment::~Environment()
{
}

void Environment::step()
{
}

bool Environment::isDone() const
{
    return m_Done;
}