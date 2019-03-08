#include "initialise.h"

//qreal const car::carSize=1.;

QPointF WorldSize()
{
    return QPointF(450,450);
}

void car::Ini()
{
    // initialise constants
    mass = 60;
    spacing = 7;
}

int RenderingTimeDelay()
{
    // slowing before updating the picture (ms)
    return 50; // 50
}

void InitialiseWorld(World* world, QVector<car*>* carsVector, QVector<trafficlight*>* lightVector)
{
    Q_UNUSED(world);
    carsVector->push_back(new car(0,5));
    carsVector->push_back(new car(3,8));
    lightVector->push_back(new trafficlight(4,0,2));

}

