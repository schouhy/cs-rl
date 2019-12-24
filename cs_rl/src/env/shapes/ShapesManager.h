#ifndef TILE_H
#define TILE_H

#include "Segment.h"
#include "Ray.h"
#include "utils.h"



class ShapesManager
{
friend class Environment;
private:
    struct  Anchor {
        int x, y;
        // Anchor(int x, int y) : x(x), y(y) {}
        bool const operator==(const Anchor &other) const { return x == other.x && y == other.y;}
        bool const operator<(const Anchor &other) const {return x < other.x || (x == other.x && y < other.y);}
    };

    // Variables
    const int m_NumberRows, m_NumberColumns;
    float m_Width, m_Height;
    std::map<Anchor, std::vector<Segment*>> m_Walls;

    // Functions
    bool intersectsAnchor(const Anchor& anchor, const Segment& segment);
public:
    // Constructor / Destructor
    ShapesManager(int n_rows, int n_columns, const std::vector<Segment*>& walls);
    ~ShapesManager();

    // Functions
    float distanceWalls(const Ray& ray);
    float distanceWalls(const Circle& circle);
};

#endif // TILE_H