#include "PlayerAnimation.h"


// Constructor / Destructor

PlayerAnimation::PlayerAnimation(sf::Sprite& sprite, const Player& player, std::map<std::string, std::vector<sf::Texture*>>& textures)
    : m_Sprite(sprite), m_Player(player), m_Textures(textures), m_PlayerLastState(0), m_CurrentIndex(0)
{
}

PlayerAnimation::~PlayerAnimation()
{
}

// Functions

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
            m_Sprite.setTexture(*m_Textures["Idle"][m_CurrentIndex % 20]);
            m_CurrentIndex += 1;
            m_TimeSinceLastUpdate = sf::Time::Zero;
        }
    }
    else
    {
        m_TimeSinceLastUpdate += m_Clock.restart();
        if (m_TimeSinceLastUpdate > sf::seconds(TIME_PER_FRAME))
        {
            m_Sprite.setTexture(*m_Textures["Forward"][m_CurrentIndex % 20]);
            m_CurrentIndex += 1;
            m_TimeSinceLastUpdate = sf::Time::Zero;
        }
    }

    // Transformations
    m_Sprite.setPosition(m_Player.getPosition().x, m_Player.getPosition().y);
    m_Sprite.setOrigin(95., 120.);
    m_Sprite.setScale(sf::Vector2f(0.4, 0.4));
    m_Sprite.setRotation(glm::orientedAngle(glm::vec2(1.,0.), glm::normalize(m_Player.getDirection()))*180.f/3.14159f);
}

void PlayerAnimation::checkReset()
{
    if(m_PlayerLastState != m_Player.getMovementState())
    {
        m_TimeSinceLastUpdate = sf::Time::Zero;
        m_CurrentIndex = 0;
        m_PlayerLastState = m_Player.getMovementState();
    }
}