#include "InteractiveGameState.h"


// Constructcor / Destructor

InteractiveGameState::InteractiveGameState(sf::RenderWindow& window)
    : LayerStack(window)
{
    initEnvironment();
    initLayers();
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


void InteractiveGameState::initLayers()
{
    // Input that affects Environment
    m_Layers.push_back(new PlayInputHandler(m_Window, *m_Environment));

    // Retrieves information from Environment to render it on the screen
    m_Layers.push_back(new VisualizationStack(m_Window, *m_Environment));
}


