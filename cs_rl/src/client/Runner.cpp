#include "Runner.h"


// Constructor / Destructor
Runner::Runner()
{
    initWindow();
    initLayerStack();
}

// Initializers
void Runner::initWindow()
{
    m_Window =  new sf::RenderWindow(sf::VideoMode(1024, 768), "Las tinieblas de sasa");
    m_Window->setFramerateLimit(90);
    m_Window->setVerticalSyncEnabled(true);
}



void Runner::initLayerStack()
{
    m_StateStack.push(GAMEMODE);
}


// Functions


void Runner::render() 
{
    m_Window->clear(sf::Color(100, 100, 100));
    // Render top of m_LayerStack
    if (!m_StateStack.empty())
    {
        m_StateStack.top()->render();
    }
    m_Window->display();
}

void Runner::update()
{
    // Update top of m_LayerStack
    if (!m_StateStack.empty())
    {
        m_StateStack.top()->update();
    }
}

void Runner::run()
{
    m_TimeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(TIME_PER_FRAME);
    // Main Loop
    while (m_Window->isOpen())
    {
        m_TimeSinceLastUpdate += m_Clock.restart();
        // Fixed time step
        while (m_TimeSinceLastUpdate > TimePerFrame)
        {
            m_TimeSinceLastUpdate -= TimePerFrame;
            update();
        }
        render();
    }
}