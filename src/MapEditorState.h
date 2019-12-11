#ifndef MAPEDITORSTATE_H
#define MAPEDITORSTATE_H

#include "LayerStack.h"
#include "MapLayer.h"
#include "EditInputHandler.h"



class MapEditorState : public LayerStack
{
private:
    // Variables
    sf::Texture m_BackgroundTexture;

    // Initializers
    void initTextures();
    void initLayers();
public:
    MapEditorState(sf::RenderWindow& window);
    ~MapEditorState();

    std::vector<Vertex> m_Vertices;
};




#endif // MAPEDITORSTACK_H