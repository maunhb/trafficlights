#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H
#include"map.h"

class trafficlight
{
private:
    PointF positionL;
    PointF positionU;
    PointF positionR;
    PointF positionD;
    PointF lightPosition;
public:
    trafficlight(int x);
    int horiz_state;
    int vert_state;

    int getHorizState(){return horiz_state;}
    int getVertState(){return vert_state;}
    QPoint getL(){return QPoint(positionL.x(),positionL.y());}
    QPoint getR(){return QPoint(positionR.x(),positionR.y());}
    QPoint getD(){return QPoint(positionD.x(),positionD.y());}
    QPoint getU(){return QPoint(positionU.x(),positionU.y());}
};

#endif // TRAFFICLIGHT_H
