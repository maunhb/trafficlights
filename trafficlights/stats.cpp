#include "stats.h"

stats::stats(World* world, double dTime)
{
    stats::cars = world->getCars();
    stats::lights = world->getLights();
    stats::total_num_cars = cars->size()+1;
    stats::num_waiting = world->num_waiting;
//    stats::car_journey_time = 0;
//    stats::time_cars_waiting = 0;
    stats::current_time = dTime;
}

