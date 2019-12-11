#ifndef MAPEDITORSTATE_H
#define MAPEDITORSTATE_H

#include "client/layers/LayerStack.h"
#include "client/layers/MapLayer.h"
#include "client/layers/EditInputHandler.h"



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