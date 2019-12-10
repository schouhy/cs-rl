#ifndef EDITINPUTHANDLER_H
#define EDITINPUTHANDLER_H

#include "Layer.h"
#include "Environment.h"


struct Vertex
{
    int x, y;
};


class EditInputHandler : public Layer
{
private:
    // Variables
    std::vector<Vertex>& m_Vertices;
    sf::Event m_Event;

    // Functions
    void processSFMLEvents(ActionInput& action);
public:
    EditInputHandler(sf::RenderWindow& window, std::vector<Vertex>& vertices);
    ~EditInputHandler() = default;

    // Functions
    void update() override;
    void render() override;
};



#endif // EDITINPUTHANDLER_H