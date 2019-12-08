#include "PlayerAnimation.h"


// Constructor / Destructor

PlayerAnimation::PlayerAnimation(const Player& player, textures_map& textures)
    : m_Player(player), m_Textures(textures), m_LastState(0), m_CurrentIndex(0)
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

void PlayerAnimation::transform()
{
    m_Sprite.setPosition(m_Player.getPosition().x, m_Player.getPosition().y);
    m_Sprite.setOrigin(95.f, 120.f);
    m_Sprite.setScale(sf::Vector2f(0.4f, 0.4f));
    m_Sprite.setRotation(glm::orientedAngle(glm::vec2(1.f,0.f), glm::normalize(m_Player.getDirection()))*180.f/3.14159f);
}

void PlayerAnimation::playNextFrame(std::string key, int speed_factor)
{
    m_TimeSinceLastUpdate += m_Clock.restart();
    if (m_TimeSinceLastUpdate > sf::seconds(TIME_PER_FRAME*speed_factor))
    {
        m_Sprite.setTexture(*m_Textures[key][m_CurrentIndex],true);
        m_CurrentIndex += 1;
        m_CurrentIndex = m_CurrentIndex % m_Textures[key].size();
        m_TimeSinceLastUpdate = sf::Time::Zero;
    }
}

void PlayerAnimation::update()
{
    // Resets animation when changing movement state
    checkReset();

    // Chooses animation
    if(m_Player.getMovementState() == Forward)
        playNextFrame("Forward", 1);
    else if(m_Player.getMovementState() & Shoot)
        playNextFrame("Shoot", 1);
    else
        playNextFrame("Idle", 4);
    transform();
}

void PlayerAnimation::render(sf::RenderTarget *target)
{
    target->draw(m_Sprite);
}