#ifndef LAYER_H
#define LAYER_H


#include <iostream>
#include <chrono>
#include <experimental/filesystem>
#include <stack>

#include <SFML/Graphics.hpp>

#define TIME_PER_FRAME 1.f/60.f
#define MOUSEPOSITION 200
  
//#define MAPEDITOR

#ifdef MAPEDITOR
#define GAMEMODE std::make_unique<MapEditorState>(*m_Window)
#else
#define GAMEMODE std::make_unique<InteractiveGameState>(*m_Window)
#endif


class Layer
{
protected:
    sf::RenderWindow& m_Window;
public:
    // Constructor / Destructor
    Layer(sf::RenderWindow& window);
    virtual ~Layer();

    // Functions
    virtual void update() = 0;
    virtual void render() = 0;
};

#endif // LAYER_H