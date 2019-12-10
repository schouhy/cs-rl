#ifndef VISUALIZATIONSTACK_H
#define VISUALIZATIONSTACK_H

#include "Environment.h"
#include "PlayerSpriteLayer.h"
#include "BackgroundLayer.h"
#include "LayerStack.h"


class VisualizationStack : public LayerStack
{
private:
    Environment *m_Environment;
    std::map<std::string, std::vector<sf::Texture*>> m_PlayerTextures;
    sf::Texture m_BackgroundTexture;

    // Initializers
    void initSprites();
    void initTextures();

    // Functions
    void loadTexturesFromFolder(int number, std::string path, std::string key, std::map<std::string, std::vector<sf::Texture*>>& map);

public:
    // Constructor / Destructor
    VisualizationStack(sf::RenderWindow& window, Environment *env);
    virtual ~VisualizationStack();
};


#endif // VISUALIZATIONSTACK_H