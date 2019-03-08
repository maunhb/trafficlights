#ifndef STATS_H
#define STATS_H
#include"world.h"

class stats
{
public:
    stats(World* world);
    int total_num_cars;
    qreal time_cars_waiting;
    qreal car_journey_time;
    const QVector<car*>* cars;
    const QVector<trafficlight*>* lights;
};

#endif // STATS_H
