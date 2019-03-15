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
    int spacing;
    PointF Position;
    PointF Destination;
    bool horiz_close, vert_close;
    qreal waitingTime;
    int positionNode, nextNode, destinationNode;

public:
    bool wait;
    car(int positionNode, int destinationNode, QColor color = QColor::fromRgb(255,0,0,125));
    virtual ~car();
 //   car(int positionNode, int destinationNode, pathfinder *paths, QColor color = QColor::fromRgb(255,0,0,125));

    virtual void computeNextState(QVector<car*> *cars, QVector<trafficlight*> *lights);
    virtual void closeTrafficLight(QVector<trafficlight*> *lights);
    virtual void closeCar(QVector<car*> *cars);
    void Drive();
    void Ini();

    PointF getPosition() {return Position;}
    PointF getDestination() {return Destination;}
    QColor getColor() const {return color;}
    PointPolar getVelocity() const {return Velocity;}

  //  PointPolar getVelocity() const {return Velocity;}
};

#endif // CAR_H
