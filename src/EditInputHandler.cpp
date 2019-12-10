#include "EditInputHandler.h"

EditInputHandler::EditInputHandler(sf::RenderWindow& window, std::vector<Vertex>& vertices)
    : Layer(window), m_Vertices(vertices)
{
}

void EditInputHandler::update()
{
    while(m_Window.pollEvent(m_Event))
    {
        if (m_Event.type == sf::Event::Closed)
            m_Window.close();

        if(m_Event.type == sf::Event::MouseButtonReleased)
            if(m_Event.mouseButton.button == sf::Mouse::Left)
                std::cout << "ahora si" << std::endl;
    }
}

void EditInputHandler::render()
{
}
