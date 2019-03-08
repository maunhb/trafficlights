#ifndef CAR_H
#define CAR_H
#include "qdebug.h"
#include <QVector>
#include <qcolor.h>
#include <qmath.h>
//#include "pathfinder.h"
#include"trafficlight.h"

class car
{
    QColor color;
    PointPolar Velocity;
    qreal direction;
    bool stopped;
    qreal mass;
    qreal max_speed;
    PointF Position;
    PointF Destination;
    int positionNode, nextNode, destinationNode;
  //  QVector<trafficlight*>* lightVector;

public:
    car(int positionNode, int destinationNode, QColor color = QColor::fromRgb(255,0,0,125));
    virtual ~car();
 //   car(int positionNode, int destinationNode, pathfinder *paths, QColor color = QColor::fromRgb(255,0,0,125));

    virtual void computeNextState(QVector<car*> *cars);
    void Drive();

    PointF getPosition() {return Position;}
    PointF getDestination() {return Destination;}
    QColor getColor() const {return color;}
    PointPolar getVelocity() const {return Velocity;}

  //  PointPolar getVelocity() const {return Velocity;}
};

#endif // CAR_H
