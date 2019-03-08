#ifndef WORLDPAINTER_H
#define WORLDPAINTER_H
#include "world.h"
#include <QPainter>

class MainWindow;

class WorldPainter
{
    MainWindow* window;
    QPainter* painter;
    QPoint size;
    QPointF &resize(QPointF&);
public:
    WorldPainter(QPainter* painter, MainWindow *window);
    void repaint(World* world, map *worldMap);

    bool paintWaypoints;
    bool paintNetwork;
};

#endif // WORLDPAINTER_H
