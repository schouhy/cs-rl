#include "VisualizationStack.h"

// Constructor / Destructor

VisualizationStack::VisualizationStack(Environment *env)
{
    m_Environment = env;
    initTextures();
    initSprites();
}


VisualizationStack::~VisualizationStack()
{
    for (auto const& [key, val] : m_PlayerTextures)
        for(auto texture : val)
            delete texture;
}

// Initializers

void VisualizationStack::initTextures()
{
    //Background
    m_BackgroundTexture.setRepeated(true);
    m_BackgroundTexture.loadFromFile("src/sprites/map/bckg.jpg");
    // Player
    loadTexturesFromFolder(20, "src/sprites/player/rifle/move/", "Forward", m_PlayerTextures);
    loadTexturesFromFolder(20, "src/sprites/player/rifle/idle/", "Idle", m_PlayerTextures);
    loadTexturesFromFolder(3, "src/sprites/player/rifle/shoot/", "Shoot", m_PlayerTextures);
}

void VisualizationStack::initSprites()
{
    // Background
    m_Layers.push_back(new BackgroundLayer(m_BackgroundTexture));

    // Players
    for (auto player : m_Environment->getPlayers())
        m_Layers.push_back(new PlayerAnimation(*player, m_PlayerTextures));
}

// Functions

void VisualizationStack::loadTexturesFromFolder(int number, std::string path, std::string key, std::map<std::string, std::vector<sf::Texture*>>& map)
{
    for (int index = 0; index < number; ++index)
    {
        map[key].push_back(new sf::Texture);
        map[key].back()->loadFromFile(path + std::to_string(index) + ".png");
    }
}