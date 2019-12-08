#include "Visualization.h"

// Constructor / Destructor
Visualization::Visualization(Environment *env)
{
    m_Environment = env;
    initPlayerSprites();
}


Visualization::~Visualization()
{
    delete m_PlayerAnimation;
    for (auto const& [key, val] : m_PlayerTextures)
        for(auto texture : val)
            delete texture;
}

// Initializers

void Visualization::initPlayerSprites()
{
    // Textures
    //   move
    loadTexturesFromFolder("src/sprites/rifle/move/", "Forward");
    loadTexturesFromFolder("src/sprites/rifle/idle/", "Idle");
    
    // Sprites
    m_PlayerAnimation = new PlayerAnimation(m_PlayerSprite, *m_Environment->getPlayer(), m_PlayerTextures);
}

// Functions


void Visualization::updatePlayerAnimation()
{
    m_PlayerAnimation->update();
}


void Visualization::loadTexturesFromFolder(std::string path, std::string key)
{
    for (int index = 0; index < 20; ++index) // Temporal
    {
        m_PlayerTextures[key].emplace_back(new sf::Texture);
        m_PlayerTextures[key].back()->loadFromFile(path + std::to_string(index) + ".png");
    }
}

void Visualization::update()
{
    updatePlayerAnimation();
}



void Visualization::render(sf::RenderTarget *target)
{
    target->draw(m_PlayerSprite);
}



