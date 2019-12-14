#include "DebugLayer.h"

DebugLayer::DebugLayer(sf::RenderWindow& window, Environment& env) 
    : Layer(window), m_Window(window), m_Environment(env)
{
}

DebugLayer::~DebugLayer()
{
}

void DebugLayer::update()
{
}

void DebugLayer::render()
{
    //for (auto segment : m_Environment.m_CollisionBoxTest)
    //   std::cout << m_Environment.getPlayers().at(0)->getShape()->collidesWith(*segment) << std::endl;
}