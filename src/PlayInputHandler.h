#ifndef PLAYINPUTHANDLER_H
#define PLAYINPUTHANDLER_H

#include "Layer.h"
#include "Environment.h"


class PlayInputHandler : public Layer
{
private:
    // Variables
    Environment& m_Environment;
    sf::Event m_Event;
    
    // Functions
    void processSFMLEvents(ActionInput& action);
public:
    PlayInputHandler(sf::RenderWindow& window, Environment& env);
    ~PlayInputHandler() = default;
    
    // Functions
    void update() override;
    void render() override;
};



#endif // PLAYINPUTHANDLER_H