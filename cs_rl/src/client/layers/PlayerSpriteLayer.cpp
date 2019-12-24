#include "PlayerSpriteLayer.h"


// Constructor / Destructor

PlayerSpriteLayer::PlayerSpriteLayer(sf::RenderWindow& window, const Player& player, textures_map& textures)
    : Layer(window), m_Player(player), m_Textures(textures), m_LastState(0), m_CurrentIndex(0), m_Color(sf::Color::White)
{
    m_Aim = new sf::VertexArray(sf::Lines, 2);
}

PlayerSpriteLayer::PlayerSpriteLayer(sf::RenderWindow& window,const Player& player, textures_map& textures, sf::Color color)
    :  Layer(window), m_Player(player), m_Textures(textures), m_LastState(0), m_CurrentIndex(0), m_Color(color)
{
    m_Aim = new sf::VertexArray(sf::Lines, 2);
}

PlayerSpriteLayer::~PlayerSpriteLayer()
{
    delete m_Aim;
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
    sf::Vector2u scale = m_Window.getSize();
    Vec2 pos = m_Player.getPosition();
    Vec2 dir = m_Player.getDirection();
    float dist_ahead = m_Player.getDistanceAhead();
    
    ////////   Debug ///////////
    m_CollidingArea.setFillColor(sf::Color::Red);
    m_CollidingArea.setPointCount(30);
    m_CollidingArea.setRadius(6e-3f*scale.x);
    m_CollidingArea.setOrigin(6e-3f*scale.x, 6e-3f*scale.x);
    m_CollidingArea.setPosition(pos.x*scale.x, pos.y*scale.y);
    ////////////////////////////

    // Aim
    (*m_Aim)[0].position = sf::Vector2f(pos.x*scale.x, pos.y*scale.y);
    (*m_Aim)[0].color = sf::Color(0, 255, 0, 128);
    (*m_Aim)[1].position = sf::Vector2f((pos.x + dist_ahead*dir.x)*scale.x, (pos.y + dist_ahead*dir.y)*scale.y);
    (*m_Aim)[1].color = sf::Color(255, 0, 0, 128);
    
    // Player
    m_Sprite.setOrigin(145.f, 120.f);
    m_Sprite.setColor(m_Color);
    m_Sprite.setPosition(pos.x*scale.x, pos.y*scale.y);
    
    m_Sprite.setScale(sf::Vector2f(8e-5f*scale.x, 8e-5f*scale.x));
    m_Sprite.setRotation(orientedAngle(Vec2(1.f,0.f), normalize(m_Player.getDirection()))*180.f/3.14159f);
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
    m_Window.draw(*m_Aim);
    //Debug
   // m_Window.draw(m_CollidingArea);
}