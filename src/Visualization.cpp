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
    for (auto texture : m_PlayerTextures)
        delete texture;
}

// Initializers

void Visualization::initPlayerSprites()
{
    // Textures
    std::string fname = "src/sprites/rifle/move/survivor-move_rifle_";
    for (int index = 0; index < 20; ++index) // Temporal
    {
        m_PlayerTextures.emplace_back(new sf::Texture);
        m_PlayerTextures.back()->loadFromFile(fname + std::to_string(index) + ".png");
    }
    
    // Sprites
    m_PlayerAnimation = new PlayerAnimation(m_PlayerSprite, *m_Environment->getPlayer(), m_PlayerTextures);
}

// Functions

void Visualization::update()
{
    updatePlayerAnimation();
}


void Visualization::updatePlayerAnimation()
{
    m_PlayerAnimation->update();
}


void Visualization::render(sf::RenderTarget *target)
{
    target->draw(m_PlayerSprite);
}



