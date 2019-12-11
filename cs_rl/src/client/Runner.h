#ifndef RUNNER_H
#define RUNNER_H

#include "states/InteractiveGameState.h"
#include "states/MapEditorState.h"


class Runner
{
private:
    //Initializers
    void initWindow();
    void initLayerStack();

    // Functions
    void render();
    void update();

    //Variables
    std::stack<std::shared_ptr<LayerStack>> m_StateStack;
    sf::RenderWindow *m_Window;    
    sf::Event m_Event;
    sf::Clock m_Clock;
    sf::Time m_TimeSinceLastUpdate;
public:
    Runner();
    ~Runner() = default;

    //Functions
    void run();
};

#endif