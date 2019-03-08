#include "stats.h"

stats::stats(World* world)
{
    stats::cars = world->getCars();
    stats::lights = world->getLights();
    stats::total_num_cars = cars->size()+1;
    stats::car_journey_time = 0;
    stats::time_cars_waiting = 0;

}

