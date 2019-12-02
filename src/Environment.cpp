#include "Environment.h"


Environment::Environment() 
{
    m_Done = false;
    m_Entity = new Entity();
}

Environment::~Environment()
{
    delete m_Entity;
}

void Environment::step()
{
    std::cout << m_Entity->getWidth() << std::endl;
}

bool Environment::isDone() const
{
    return m_Done;
}