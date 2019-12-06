#include "Runner.h"

#define MOUSEPOSITION 200

// Constructor / Destructor
Runner::Runner()
{
    initWindow();
    initEnvironment();
    sf::Mouse::setPosition(sf::Vector2i(MOUSEPOSITION, MOUSEPOSITION));
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
    m_Window->setMouseCursorVisible(false);
}

void Runner::initEnvironment()
{
    m_Environment = new Environment();
    m_Visualization = new Visualization(m_Environment);
}


// Functions
void Runner::processSFMLEvents(int& pos_action, float& angle_action)
{
    while (m_Window->pollEvent(m_Event))
        {
            if (m_Event.type == sf::Event::Closed)
                m_Window->close();
        }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        pos_action |= StrafeLeft;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        pos_action |=  StrafeRight;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        pos_action |=  Backward;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        pos_action |=  Forward;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
        pos_action |= Walk;
    angle_action = (sf::Mouse::getPosition().x - MOUSEPOSITION)/500.f;
    //m_CurrentMouse_x = new_CurrentMouse_x;
    sf::Mouse::setPosition(sf::Vector2i(MOUSEPOSITION, MOUSEPOSITION));
}

void Runner::updateLogic()
{
    int pos_action = 0;
    float angle_action;
    processSFMLEvents(pos_action, angle_action);
    m_Environment->step(pos_action, angle_action);
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