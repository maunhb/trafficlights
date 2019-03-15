#ifndef WORLD_H
#define WORLD_H

#include "car.h"
#include <QPoint>
#include <QVector>

class World
{
public:
    double maxX; // 500
    double maxY; // 500
    World(QPointF size);
    void computeIteration(double dTime);
    int carspace;

    QPointF size;
    QVector<car*>* carsVector;
    QVector<trafficlight*>* lightVector;
  //  pathfinder* paths;

    const QVector<car*>* getCars() {return carsVector;}
    const QVector<trafficlight*>* getLights() {return lightVector;}
    int num_waiting;
};
#endif // WORLD_H
