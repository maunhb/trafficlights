#ifndef MAP_H
#define MAP_H
#include"pointf.h"

static const int num_tiles=9;
const int num_intersections=1;

struct cell{
    int parent;
    bool inter, horiz, vert;
};
struct wayPoints{
    PointF location;
};

const wayPoints tileLocations[num_tiles] = {
    PointF(75,375),
    PointF(225,375),
    PointF(375,375),
    PointF(75,225),
    PointF(225,225),
    PointF(375,225),
    PointF(75,75),
    PointF(225,75),
    PointF(375,75)
};

const wayPoints nodeLocations[12] = {
    PointF(0,232.5), // 0
    PointF(217.5,232.5), // 1
    PointF(217.5,450), // 2
    PointF(232.5,450), //3
    PointF(232.5,232.5), //4
    PointF(450,232.5), // 5
    PointF(450,217.5), // 6
    PointF(232.5,217.5), // 7
    PointF(232.5,0), // 8
    PointF(217.5,0), // 9
    PointF(217.5,217.5), // 10
    PointF(0,217.5) // 11
};

const bool adjacency[12][12] = {
    { 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 1, 0, 1, 0, 0, 1, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    { 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    { 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};


class map
{
    bool intersection;
    bool road_horizontal;
    bool road_vertical;
public:
    map();
    cell tiles[num_tiles];
    bool isHoriz(int i){return tiles[i].horiz;}
 //   const wayPoints nodeLocations;
 //   const bool adjacency;
 //   PointF getLocation(const wayPoints nodeLoc){return nodeLoc.location;}
 //   int astar(int positionNode, int destinationNode);

};



#endif // MAP_H

