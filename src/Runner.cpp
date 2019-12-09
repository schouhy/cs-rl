#include "Runner.h"


// Constructor / Destructor
Runner::Runner()
{
    initWindow();
    initEnvironment();
    initLayerStack();
}


Runner::~Runner() 
{
    delete m_Window;
    delete m_Environment;
}


// Initializers
void Runner::initWindow()
{
    m_Window =  new sf::RenderWindow(sf::VideoMode(1024, 1024), "Las tinieblas de sasa");
    m_Window->setFramerateLimit(90);
    m_Window->setVerticalSyncEnabled(true);
    m_Window->setMouseCursorVisible(false);
}


void Runner::initEnvironment()
{
    m_Environment = new Environment();
}


void Runner::initLayerStack()
{
    m_StateStack.push(std::make_shared<VisualizationStack>(m_Environment));
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
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        pos_action |= Shoot;
    angle_action = (sf::Mouse::getPosition().x - MOUSEPOSITION)/500.f;

    sf::Mouse::setPosition(sf::Vector2i(MOUSEPOSITION, MOUSEPOSITION));
    //std::cout << sf::Mouse::getPosition(*m_Window).x << " " << sf::Mouse::getPosition(*m_Window).y << std::endl;
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
    m_Window->clear(sf::Color(34,139,34));

    // Render top of m_LayerStack
    if (!m_StateStack.empty())
    {
        m_StateStack.top()->update();
        m_StateStack.top()->render(m_Window);
    }
    m_Window->display();
}

void Runner::run()
{
    m_TimeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(TIME_PER_FRAME);
    while (m_Window->isOpen())
    {
        m_TimeSinceLastUpdate += m_Clock.restart();
        while (m_TimeSinceLastUpdate > TimePerFrame)
        {
            m_TimeSinceLastUpdate -= TimePerFrame;
            updateLogic();
        }
        render();
    }
}