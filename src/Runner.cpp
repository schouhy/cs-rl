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
    m_Window =  new sf::RenderWindow(sf::VideoMode(640, 480), "Las tinieblas de sasa");
    m_Window->setFramerateLimit(90);
    m_Window->setVerticalSyncEnabled(true); 
}

void Runner::initEnvironment()
{
    m_Environment = new Environment();
    m_Visualization = new Visualization(m_Environment);
}


// Functions
int Runner::processSFMLEvents()
{
    int action = 0;
    while (m_Window->pollEvent(m_Event))
        {
            if (m_Event.type == sf::Event::Closed)
                m_Window->close();
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        action |= StrafLeft;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        action |=  StrafRight;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))
        action |=  Backward;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
        action |=  Forward;
    return action;
}

void Runner::updateLogic()
{
    int action = processSFMLEvents();
    m_Environment->step(action);
}

void Runner::render() 
{
    m_Window->clear();

    // Render
    m_Visualization->update();
    m_Visualization->render(m_Window);


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