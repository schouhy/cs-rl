#include "VisualizationLayer.h"

// Constructor / Destructor

VisualizationLayer::VisualizationLayer(Environment *env)
{
    m_Environment = env;
    initPlayerSprites();
}


VisualizationLayer::~VisualizationLayer()
{
    delete m_PlayerVisualization;
    for (auto const& [key, val] : m_PlayerBodyTextures)
        for(auto texture : val)
            delete texture;
}

// Initializers

void VisualizationLayer::initPlayerSprites()
{
    // Textures
    //   body
    loadTexturesFromFolder(20, "src/sprites/player/rifle/move/", "Forward", m_PlayerBodyTextures);
    loadTexturesFromFolder(20, "src/sprites/player/rifle/idle/", "Idle", m_PlayerBodyTextures);
    //   feet
    loadTexturesFromFolder(20, "src/sprites/player/feet/run/", "Forward", m_PlayerFeetTextures);
    loadTexturesFromFolder(1, "src/sprites/player/feet/idle/", "Idle", m_PlayerFeetTextures);
    
    // Sprites
    m_PlayerVisualization = new PlayerVisualization(*m_Environment->getPlayer(), m_PlayerBodyTextures, m_PlayerFeetTextures);
}

// Functions


void VisualizationLayer::updatePlayerAnimation()
{
    m_PlayerVisualization->update();
}


void VisualizationLayer::loadTexturesFromFolder(int number, std::string path, std::string key, std::map<std::string, std::vector<sf::Texture*>>& map)
{
    for (int index = 0; index < number; ++index)
    {
        map[key].push_back(new sf::Texture);
        map[key].back()->loadFromFile(path + std::to_string(index) + ".png");
    }
}

void VisualizationLayer::update()
{
    updatePlayerAnimation();
}



void VisualizationLayer::render(sf::RenderTarget *target)
{
    m_PlayerVisualization->render(target);
}



