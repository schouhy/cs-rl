#include "Runner.h"


// Constructor / Destructor
Runner::Runner()
{
    initWindow();
    initEnvironment();
}

Runner::~Runner() 
{
    delete m_Window;
    delete m_Environment;
}


// Initializers
void Runner::initWindow()
{
    m_Window =  new sf::RenderWindow(sf::VideoMode(640, 480), "SFML Application");
    m_Window->setFramerateLimit(90);
    m_Window->setVerticalSyncEnabled(true);

}

void Runner::initEnvironment()
{
    m_Environment = new Environment();
}


// Functions
void Runner::processSFMLEvents()
{
    while (m_Window->pollEvent(m_Event))
        {
            if (m_Event.type == sf::Event::Closed)
            m_Window->close();
        }
}

void Runner::updateLogic()
{
    processSFMLEvents();
    m_Environment->step();
}

void Runner::render() 
{
    m_Window->clear();
    m_Window->display();
}

void Runner::run()
{
    sf::Clock clock;
    m_TimeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(TIME_PER_FRAME);
    while (m_Window->isOpen())
    {
        m_TimeSinceLastUpdate += clock.restart();
        while (m_TimeSinceLastUpdate > TimePerFrame)
        {
            m_TimeSinceLastUpdate -= TimePerFrame;
            updateLogic();
        }
        render();
    }
}