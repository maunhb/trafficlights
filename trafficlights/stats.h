#ifndef STATS_H
#define STATS_H
#include"world.h"

class stats
{
public:
    stats(World* world,double dTime);
    int total_num_cars;
    int num_waiting;
    qreal time_cars_waiting;
    qreal car_journey_time;
    const QVector<car*>* cars;
    const QVector<trafficlight*>* lights;
    double current_time;
};

#endif // STATS_H
