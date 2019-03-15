#include "worlditerator.h"
#include "initialise.h"

WorldIterator::WorldIterator(World *mainWorld, WorldPainter *worldPainter, map *worldMap)
{
    WorldIterator::mainWorld = mainWorld;
    WorldIterator::worldPainter = worldPainter;
    WorldIterator::worldMap = worldMap;
    statVector = new QVector<stats*>();
    WorldIterator::changeLights = new smartlight();

    timerTickDelayMsec = RenderingTimeDelay();
    QObject::connect(this, SIGNAL(timeout()), this, SLOT(timerTick()));
    setInterval(timerTickDelayMsec);
    time = 0;
}

void WorldIterator::timerTick()
{
    mainWorld->computeIteration(timerTickDelayMsec/1000.0);
    statVector->push_back(new stats(mainWorld,timerTickDelayMsec/1000.0));
    changeLights->change_lights_horiz(mainWorld->lightVector,statVector);
    changeLights->change_lights_vert(mainWorld->lightVector,statVector);
    worldPainter->repaint(mainWorld, worldMap);
    time += timerTickDelayMsec;
}
