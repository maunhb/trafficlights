#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H
#include"stats.h"

class smartlight
{
public:
    smartlight(stats* stat);
    void change_lights_vert(QVector<trafficlight*>* lightVector);
    void change_lights_horiz(QVector<trafficlight*>* lightVector);
};

#endif // SMARTLIGHT_H
