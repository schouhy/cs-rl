#ifndef INTERACTIVEGAMESTATE_H
#define INTERACTIVEGAMESTATE_H


#include "LayerStack.h"
#include "Environment.h"
#include "VisualizationStack.h"
#include "UserInputLayer.h"

class InteractiveGameState : public LayerStack
{
private:
    Environment *m_Environment;

    // Initializers
    void initEnvironment(); 
    void initLayerStack(sf::Event& event);

    // Functions
    void processSFMLEvents(ActionInput& input);
    void updateLogic();

public:
    // Constructor / Destructor
    InteractiveGameState(sf::Event& event);
    ~InteractiveGameState();
};


#endif // INTERACTIVEGAMESTATE_H