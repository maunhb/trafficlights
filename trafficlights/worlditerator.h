#ifndef WORLDITERATOR_H
#define WORLDITERATOR_H

#include <QTimer>
#include <QObject>
#include "qdebug.h"
#include "worldpainter.h"
#include"smartlight.h"
//#include<QApplication>

class WorldIterator : public QTimer
{
    Q_OBJECT
    World* mainWorld;
    WorldPainter* worldPainter;
    map* worldMap;
    double time;
    int timerTickDelayMsec;
    smartlight* changeLights;
    QVector<stats*>* statVector;
public:
    WorldIterator(World* mainWorld, WorldPainter* worldPainter, map *worldMap);
public slots:
    void timerTick();

};

#endif // WORLDITERATOR_H
