#ifndef WORLD_H
#define WORLD_H

#include "car.h"
#include <QPoint>
#include <QVector>

class World
{
    QPointF size;
    QVector<car*>* carsVector;
    QVector<trafficlight*>* lightVector;
  //  pathfinder* paths;

public:
    double maxX; // 500
    double maxY; // 500
    World(QPointF size);
    void computeIteration(double dTime);
    int carspace;

    const QVector<car*>* getCars() {return carsVector;}
    const QVector<trafficlight*>* getLights() {return lightVector;}
};
#endif // WORLD_H
