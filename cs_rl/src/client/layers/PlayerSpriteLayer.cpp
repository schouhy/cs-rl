#include "PlayerSpriteLayer.h"


// Constructor / Destructor

PlayerSpriteLayer::PlayerSpriteLayer(sf::RenderWindow& window, const Player& player, textures_map& textures)
    : Layer(window), m_Player(player), m_Textures(textures), m_LastState(0), m_CurrentIndex(0), m_Color(sf::Color::White)
{
}

PlayerSpriteLayer::PlayerSpriteLayer(sf::RenderWindow& window,const Player& player, textures_map& textures, sf::Color color)
    :  Layer(window), m_Player(player), m_Textures(textures), m_LastState(0), m_CurrentIndex(0), m_Color(color)
{
}


// Functions

void PlayerSpriteLayer::checkReset()
{
    if(m_LastState != m_Player.getMovementState())
    {
        m_LastState = m_Player.getMovementState();
        m_TimeSinceLastUpdate = sf::Time::Zero;
        m_CurrentIndex = 0;
    }
}

void PlayerSpriteLayer::transform()
{
    ////////   Debug ///////////
    m_CollidingArea.setFillColor(sf::Color::Red);
    m_CollidingArea.setPointCount(30);
    m_CollidingArea.setRadius(5.f);
    m_CollidingArea.setOrigin(5.f, 5.f);
    m_CollidingArea.setPosition(m_Player.getPosition().x, m_Player.getPosition().y);
    ////////////////////////////
    m_Sprite.setOrigin(145.f, 120.f);
    m_Sprite.setColor(m_Color);
    m_Sprite.setPosition(m_Player.getPosition().x, m_Player.getPosition().y);
    m_Sprite.setScale(sf::Vector2f(0.08f, 0.08f));
    m_Sprite.setRotation(glm::orientedAngle(glm::vec2(1.f,0.f), glm::normalize(m_Player.getDirection()))*180.f/3.14159f);
}

void PlayerSpriteLayer::playNextFrame(std::string key, int speed_factor)
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

void PlayerSpriteLayer::update()
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

void PlayerSpriteLayer::render()
{    
    m_Window.draw(m_Sprite);
    //Debug
    //m_Window.draw(m_CollidingArea);
}