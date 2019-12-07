#ifndef RUNNER_H
#define RUNNER_H

#include "Visualization.h"

class Runner
{
public:
    Runner();
    ~Runner();

    //Functions
    void processSFMLEvents(int& pos_action, float& angle_action);
    void updateLogic();
    void render();
    void run();

private:
    //Initializers
    void initWindow();
    void initEnvironment();

    //Variables
    Environment *m_Environment;
    sf::Clock m_Clock;

    sf::RenderWindow *m_Window;    
    Visualization *m_Visualization;
    sf::Event m_Event;
    sf::Time m_TimeSinceLastUpdate;
};

#endif