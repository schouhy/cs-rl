#include "Environment.h"

// Constructor / Destructor
Environment::Environment() 
{
    m_Done = false;
    m_Entity = new Entity(50.f, 50.f);
}

Environment::~Environment()
{
    delete m_Entity;
}

// Accesors

const Entity * const Environment::getEntity() const 
{
    return m_Entity;
}

// Functions

void Environment::step()
{
  //  std::cout << m_Entity->getWidth() << std::endl;
}

bool Environment::isDone() const
{
    return m_Done;
}