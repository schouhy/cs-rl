#include "ShapesManager.h"

// Constructor / Destructor

ShapesManager::ShapesManager(int n_rows, int n_columns, const std::vector<Segment*>& walls)
    : m_NumberRows(n_rows), m_NumberColumns(n_columns)
{
    m_Width = 1.f / (float) n_columns;
    m_Height = 1.f / (float) n_rows;
    for (int i=0; i<n_rows; ++i)
        for (int j=0; j<n_columns; ++j)
        {
            auto& anchor = m_Walls[{i,j}];
            for (auto wall : walls)
                if(intersectsAnchor({i,j}, *wall))
                    m_Walls[{i,j}].push_back(wall);
        }
}

ShapesManager::~ShapesManager()
{
}

// Functions

bool ShapesManager::intersectsAnchor(const Anchor& anchor, const Segment& segment)
{
    float tl_x = (float) anchor.x / (float) m_NumberRows;
    float tl_y = (float) anchor.y / (float) m_NumberRows;

    float source_max_dist = -1e3f;
    float target_max_dist = -1e3f;
    bool intersects_box = false;
    
    std::vector<Segment> box;
    box.push_back(Segment({tl_x, tl_y}, {tl_x, tl_y + m_Height}));
    box.push_back(Segment({tl_x, tl_y + m_Height}, {tl_x + m_Width, tl_y + m_Height}));
    box.push_back(Segment({tl_x + m_Width, tl_y + m_Height}, {tl_x + m_Width, tl_y}));
    box.push_back(Segment({tl_x + m_Width, tl_y}, {tl_x, tl_y}));
    
    for(auto side: box)
    {
        float new_source_dist = side.normalProjection(segment.getSource());
        float new_target_dist = side.normalProjection(segment.getTarget());
        if(new_source_dist > source_max_dist)
            source_max_dist = new_source_dist;
        if(new_target_dist > target_max_dist)
            target_max_dist = new_target_dist;
        if(side.intersectsSegment(segment))
            intersects_box = true;
    }

    // Source or target of segment is inside the box
    if (source_max_dist < 0.f || target_max_dist < 0.f)
        return true;
    
    // Neither source or target of segment is inside de box, but it crosses it
    if (intersects_box)
        return true;    
    
    // Doesn't intersect
    return false;
}
/*
float Tile::distanceWalls(const Ray ray);
float Tile::distanceWalls(const Circle circle);
*/