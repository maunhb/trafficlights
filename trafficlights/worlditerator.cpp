#include "worlditerator.h"
#include "initialise.h"

WorldIterator::WorldIterator(World *mainWorld, WorldPainter *worldPainter, map *worldMap)
{
    WorldIterator::mainWorld = mainWorld;
    WorldIterator::worldPainter = worldPainter;
    WorldIterator::worldMap = worldMap;
    timerTickDelayMsec = RenderingTimeDelay();
    QObject::connect(this, SIGNAL(timeout()), this, SLOT(timerTick()));
    setInterval(timerTickDelayMsec);
    time = 0;
}

void WorldIterator::timerTick()
{
    mainWorld->computeIteration(timerTickDelayMsec/1000.0);
    worldPainter->repaint(mainWorld, worldMap);
    time += timerTickDelayMsec;
}
