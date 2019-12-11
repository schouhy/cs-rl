#include "EditInputHandler.h"

EditInputHandler::EditInputHandler(sf::RenderWindow& window, std::vector<Vertex>& vertices)
    : Layer(window), m_Vertices(vertices)
{
    m_Window.setMouseCursorVisible(true);
}

EditInputHandler::~EditInputHandler()
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
                m_Vertices.push_back({m_Event.mouseButton.x, m_Event.mouseButton.y});
    }
}

void EditInputHandler::render()
{
}
