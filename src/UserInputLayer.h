#ifndef USERINPUTLAYER_H
#define USERINPUTLAYER_H

#include "Layer.h"
#include "Environment.h"


class UserInputLayer : public Layer
{
private:
    // Variables
    Environment *m_Environment;
    sf::Event& m_Event;

    // Functions
    void processSFMLEvents(ActionInput& action);
public:
    UserInputLayer(Environment *env, sf::Event& event);
    ~UserInputLayer();
    // Functions
    void update();
    void render(sf::RenderTarget *target);
};



#endif // USERINPUTLAYER_H