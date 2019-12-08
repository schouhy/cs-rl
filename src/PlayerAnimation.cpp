#include "PlayerAnimation.h"


// Constructor / Destructor

PlayerAnimation::PlayerAnimation(const Player& player, sf::Sprite& sprite, textures_map& textures)
    : m_Player(player), m_Sprite(sprite), m_Textures(textures), m_LastState(0), m_CurrentIndex(0)
{
}

PlayerAnimation::~PlayerAnimation()
{
}

// Functions

void PlayerAnimation::checkReset()
{
    if(m_LastState != m_Player.getMovementState())
    {
        m_TimeSinceLastUpdate = sf::Time::Zero;
        m_CurrentIndex = 0;
        m_LastState = m_Player.getMovementState();
    }
}

void PlayerAnimation::update()
{
    // Resets animation when changing movement state
    checkReset();

    // Chooses animation
    if(m_Player.getMovementState() == Idle)
    {
        m_TimeSinceLastUpdate += m_Clock.restart();
        if (m_TimeSinceLastUpdate > sf::seconds(TIME_PER_FRAME*4))
        {
            m_Sprite.setTexture(*m_Textures["Idle"][m_CurrentIndex],true);
            m_CurrentIndex += 1;
            m_CurrentIndex = m_CurrentIndex % m_Textures["Idle"].size();
            m_TimeSinceLastUpdate = sf::Time::Zero;
        }
    }
    else
    {
        m_TimeSinceLastUpdate += m_Clock.restart();
        if (m_TimeSinceLastUpdate > sf::seconds(TIME_PER_FRAME))
        {
            m_Sprite.setTexture(*m_Textures["Forward"][m_CurrentIndex], true);
            m_CurrentIndex += 1;
            m_CurrentIndex = m_CurrentIndex % m_Textures["Forward"].size();
            m_TimeSinceLastUpdate = sf::Time::Zero;
        }
    }
}

void PlayerAnimation::render(sf::RenderTarget *target)
{
    target->draw(m_Sprite);
}