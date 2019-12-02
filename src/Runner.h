#ifndef RUNNER_H
#define RUNNER_H

#include "Visualization.h"

#define TIME_PER_FRAME 1.f/60.f

class Runner
{
public:
    Runner();
    ~Runner();

    //Functions
    void processSFMLEvents();
    void updateLogic();
    void render();
    void run();

private:
    //Initializers
    void initWindow();
    void initEnvironment();

    //Variables
    Environment *m_Environment;

    sf::RenderWindow *m_Window;    
    Visualization *m_Visualization;
    sf::Event m_Event;
    sf::Time m_TimeSinceLastUpdate;
};

#endif