#include "MapEditorState.h"


MapEditorState::MapEditorState(sf::RenderWindow& window)
    : LayerStack(window)
{
    initTextures();
    initLayers();
}

MapEditorState::~MapEditorState()
{
    for (auto vertex : m_Vertices)
        std::cout << vertex.x << " " << vertex.y << std::endl;
}
// Functions


void MapEditorState::initLayers()
{
    m_Layers.push_back(new BackgroundLayer(m_Window, m_BackgroundTexture));
    m_Layers.push_back(new EditInputHandler(m_Window, m_Vertices));
}

void MapEditorState::initTextures()
{
    m_BackgroundTexture.loadFromFile("src/sprites/map/mini_dust2.png");
}
/*
void MapEditorState::saveVertex(Vertex vertex)
{
    m_Vertices.push_back(vertex);
}
*/