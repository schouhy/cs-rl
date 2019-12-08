#include "VisualizationLayer.h"

// Constructor / Destructor

VisualizationLayer::VisualizationLayer(Environment *env)
{
    m_Environment = env;
    initPlayerSprites();
}


VisualizationLayer::~VisualizationLayer()
{
    delete m_PlayerAnimation;
    for (auto const& [key, val] : m_PlayerTextures)
        for(auto texture : val)
            delete texture;
}

// Initializers

void VisualizationLayer::initPlayerSprites()
{
    // Textures
    //   move
    loadTexturesFromFolder("src/sprites/player/rifle/move/", "Forward");
    //   idle
    loadTexturesFromFolder("src/sprites/player/rifle/idle/", "Idle");
    
    // Sprites
    m_PlayerAnimation = new PlayerAnimation(m_PlayerSprite, *m_Environment->getPlayer(), m_PlayerTextures);
}

// Functions


void VisualizationLayer::updatePlayerAnimation()
{
    m_PlayerAnimation->update();
}


void VisualizationLayer::loadTexturesFromFolder(std::string path, std::string key)
{
    for (int index = 0; index < 20; ++index)
    {
        m_PlayerTextures[key].emplace_back(new sf::Texture);
        m_PlayerTextures[key].back()->loadFromFile(path + std::to_string(index) + ".png");
    }
}

void VisualizationLayer::update()
{
    updatePlayerAnimation();
}



void VisualizationLayer::render(sf::RenderTarget *target)
{
    target->draw(m_PlayerSprite);
}



