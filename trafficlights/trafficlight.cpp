#include "trafficlight.h"

trafficlight::trafficlight(int x)
{
    trafficlight::horiz_state = 0; // 0 red, 1 amber, 2 green
    trafficlight::vert_state = 1;
    lightPosition = tileLocations[x].location;
    positionD = lightPosition+PointF(10,-20);
    positionU = lightPosition+PointF(-10,20);
    positionL = lightPosition+PointF(-20,-10);
    positionR = lightPosition+PointF(20,10);
}
