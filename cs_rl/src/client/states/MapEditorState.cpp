#include "MapEditorState.h"


MapEditorState::MapEditorState(sf::RenderWindow& window)
    : LayerStack(window)
{
    initTextures();
    initLayers();
}

MapEditorState::~MapEditorState()
{
    for (std::size_t i=0; i<m_Vertices.size(); ++i)
        std::cout << i << ") " << m_Vertices[i].x << ", " << m_Vertices[i].y << std::endl;
}
// Functions


void MapEditorState::initLayers()
{
    m_Layers.push_back(new MapLayer(m_Window, m_BackgroundTexture));
    m_Layers.push_back(new EditInputHandler(m_Window, m_Vertices));
}

void MapEditorState::initTextures()
{
    m_BackgroundTexture.loadFromFile("cs_rl/sprites/map/mini_dust2.png");
}
/*
void MapEditorState::saveVertex(Vertex vertex)
{
    m_Vertices.push_back(vertex);
}
*/