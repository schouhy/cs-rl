#ifndef INTERACTIVEGAMESTATE_H
#define INTERACTIVEGAMESTATE_H

#include "env/Environment.h"

#include "client/layers/LayerStack.h"
#include "client/layers/VisualizationStack.h"
#include "client/layers/PlayInputHandler.h"


class InteractiveGameState : public LayerStack
{
private:
    Environment *m_Environment;

    // Initializers
    void initEnvironment(); 
    void initLayers();

    // Functions
    void processSFMLEvents(ActionInput& input);
    void updateLogic();

public:
    // Constructor / Destructor
    InteractiveGameState(sf::RenderWindow& window);
    ~InteractiveGameState();
};


#endif // INTERACTIVEGAMESTATE_H