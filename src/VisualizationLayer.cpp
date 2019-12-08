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
    for (auto const& [key, val] : m_PlayerTextures)
        for(auto texture : val)
            delete texture;
}

// Initializers

void VisualizationLayer::initPlayerSprites()
{
    // Textures
    //   body
    loadTexturesFromFolder(20, "src/sprites/player/rifle/move/", "Forward", m_PlayerTextures);
    loadTexturesFromFolder(20, "src/sprites/player/rifle/idle/", "Idle", m_PlayerTextures);
    
    // Sprites
    m_PlayerVisualization = new PlayerAnimation(*m_Environment->getPlayer(), m_PlayerTextures);
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



