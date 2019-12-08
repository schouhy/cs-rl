#ifndef VISUALIZATIONSTACK_H
#define VISUALIZATIONSTACK_H

#include "Environment.h"
#include "PlayerAnimation.h"
#include "LayerStack.h"


class VisualizationStack : public LayerStack
{
private:
    Environment *m_Environment;
 
    std::map<std::string, std::vector<sf::Texture*>> m_PlayerTextures;

    // Initializers
    void initPlayerSprites();

    // Functions
    void loadTexturesFromFolder(int number, std::string path, std::string key, std::map<std::string, std::vector<sf::Texture*>>& map);

public:
    // Constructor / Destructor
    VisualizationStack(Environment *env);
    virtual ~VisualizationStack();
};


#endif // VISUALIZATIONSTACK_H