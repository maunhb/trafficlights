#ifndef SMARTLIGHT_H
#define SMARTLIGHT_H
#include"stats.h"

class smartlight
{
public:
    smartlight();
    void change_lights_vert(QVector<trafficlight*>* lightVector, QVector<stats*>* statVector);
    void change_lights_horiz(QVector<trafficlight*>* lightVector, QVector<stats*>* statVector);
};

#endif // SMARTLIGHT_H
