#ifndef INITIALISE_H
#define INITIALISE_H
#include "world.h"

void InitialiseWorld(World* world, QVector<car*>* carsVector, QVector<trafficlight*>* lightVector);
QPointF WorldSize();
int RenderingTimeDelay();

#endif // INITIALISE_H
