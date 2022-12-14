#ifndef VISUALIZATIONSTACK_H
#define VISUALIZATIONSTACK_H

#include "env/Environment.h"
#include "PlayerSpriteLayer.h"
#include "MapLayer.h"
#include "LayerStack.h"


class VisualizationStack : public LayerStack
{
private:
    const Environment& m_Environment;
    std::map<std::string, std::vector<sf::Texture*>> m_PlayerTextures;
    sf::Texture m_BackgroundTexture;

    // Initializers
    void initLayers();
    void initTextures();

    // Functions
    void loadTexturesFromFolder(int number, std::string path, std::string key, std::map<std::string, std::vector<sf::Texture*>>& map);

public:
    // Constructor / Destructor
    VisualizationStack(sf::RenderWindow& window, const Environment& env);
    virtual ~VisualizationStack();
};


#endif // VISUALIZATIONSTACK_H