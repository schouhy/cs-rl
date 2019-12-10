#include "InteractiveGameState.h"


// Constructcor / Destructor

InteractiveGameState::InteractiveGameState(sf::Event& event)
{
    initEnvironment();
    initLayerStack(event);
}

InteractiveGameState::~InteractiveGameState()
{
    delete m_Environment;
}


// Initializers

void InteractiveGameState::initEnvironment()
{
    m_Environment = new Environment();
}


void InteractiveGameState::initLayerStack(sf::Event& event)
{
    m_Layers.push_back(new UserInputLayer(m_Environment, event));
    m_Layers.push_back(new VisualizationStack(m_Environment));
}


