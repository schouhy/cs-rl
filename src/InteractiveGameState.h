#ifndef INTERACTIVEGAMESTATE_H
#define INTERACTIVEGAMESTATE_H


#include "LayerStack.h"
#include "Environment.h"
#include "VisualizationStack.h"
#include "PlayInputHandler.h"

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