#ifndef VISUALIZATIONLAYER_H
#define VISUALIZATIONLAYER_H

#include "Environment.h"
#include "PlayerAnimation.h"
#include "Layer.h"


class VisualizationLayer : public Layer
{
private:
    Environment *m_Environment;
    
    // Player 
    PlayerAnimation *m_PlayerVisualization;
    //sf::Sprite m_PlayerSprite;
    std::map<std::string, std::vector<sf::Texture*>> m_PlayerTextures;

    // Initializers
    void initPlayerSprites();

    // Functions
    void updatePlayerAnimation();
    void loadTexturesFromFolder(int number, std::string path, std::string key, std::map<std::string, std::vector<sf::Texture*>>& map);

public:
    // Constructor / Destructor
    VisualizationLayer(Environment *env);
    virtual ~VisualizationLayer() override;

    // Functions
    virtual void update() override;
    virtual void render(sf::RenderTarget *target) override;
};


#endif // VISUALIZATIONLAYER_H