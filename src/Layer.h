#ifndef LAYER_H
#define LAYER_H


#include <iostream>
#include <chrono>
#include <experimental/filesystem>
#include <stack>

#include <SFML/Graphics.hpp>

#define TIME_PER_FRAME 1.f/60.f
#define MOUSEPOSITION 200


class Layer
{
public:
    // Constructor / Destructor
    Layer();
    virtual ~Layer();

    // Functions
    virtual void update() = 0;
    virtual void render(sf::RenderTarget *target) = 0;
};

#endif // LAYER_H