#include "PlayInputHandler.h"

PlayInputHandler::PlayInputHandler(sf::RenderWindow& window, Environment& env)
    : Layer(window), m_Environment(env)
{
    m_Window.setMouseCursorVisible(false);
}


// Functions

void PlayInputHandler::processSFMLEvents(ActionInput& input)
{
    // Poll Window Events
    while (m_Window.pollEvent(m_Event))
    {
        if (m_Event.type == sf::Event::Closed)
            m_Window.close();
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
        input.pos_action |= StrafeLeft;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
        input.pos_action |=  StrafeRight;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
        input.pos_action |=  Backward;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
        input.pos_action |=  Forward;
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::LShift))
        input.pos_action |= Walk;
    if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
        input.pos_action |= Shoot;
    input.angle_action = (sf::Mouse::getPosition().x - MOUSEPOSITION)/500.f;

    sf::Mouse::setPosition(sf::Vector2i(MOUSEPOSITION, MOUSEPOSITION));
}

void PlayInputHandler::update()
{
    ActionInput user_input;
    processSFMLEvents(user_input);

    // TO-DO: Las acciones de los bots tienen que estar manejadas por otra capa distinta
    ActionInput dummy_input = {Forward, 0.01f};
    
    const std::vector<ActionInput*> inputs = {&user_input, &dummy_input};
    m_Environment.step(inputs);
}


void PlayInputHandler::render()
{
    // Debug purposes
    // std::cout << sf::Mouse::getPosition(*m_Window).x << " " << sf::Mouse::getPosition(*m_Window).y << std::endl;
}