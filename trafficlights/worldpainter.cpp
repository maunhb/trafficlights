#include "worldpainter.h"
#include "mainwindow.h"

WorldPainter::WorldPainter(QPainter *painter, MainWindow* window)
{
    WorldPainter::window = window;
    WorldPainter::painter = painter;
    size = QPoint(painter->window().width(), painter->window().height());

    painter->setBackground(QColor::fromRgb(220,220,220));
    painter->setRenderHint(QPainter::Antialiasing, true);
}

QPointF& WorldPainter::resize(QPointF& point)
{
    point.setX(point.x());
    point.setY(point.y());
    return point;
}

void WorldPainter::repaint(World *world, map *worldMap)
{
    painter->eraseRect(QRect(0,0,size.x(), size.y()));
    // draw grass
    painter->setBrush(QBrush(QColor::fromRgb(1, 150, 103)));
    painter->setPen(QPen(QColor::fromRgb(150, 150,38)));
    QRect rect(0,0,450,450);
    painter->drawRect(rect);
    // draw roads
    int left,top,width,height;
    painter->setBrush(QBrush(QColor::fromRgb(198, 140, 83)));
    painter->setPen(QPen(QColor::fromRgb(198, 140, 83)));
    for(int i = 0; i < num_tiles; i++){
        if(worldMap->tiles[i].horiz == 1){
            left = -75 + tileLocations[i].location.x();
            top = -15 + tileLocations[i].location.y();
            width = 150;
            height = 30;
            QRect drawRoad(left,top,width,height);
            painter->drawRect(drawRoad);
        }
        if(worldMap->tiles[i].vert == 1){
            left = -15 + tileLocations[i].location.x();
            top = -75 + tileLocations[i].location.y();
            width = 30;
            height = 150;
            QRect drawRoad(left,top,width,height);
            painter->drawRect(drawRoad);
        }
    }
    // draw network
    if(paintNetwork == true){
        painter->setBrush(QBrush(QColor::fromRgb(0, 153, 255, 125)));
        painter->setPen(QPen(QColor::fromRgb(0, 122, 204,125)));
        for(int i=0; i< 12; i++){
            for(int j=0; j<12; j++){
                if(adjacency[i][j]==1){
                    QPointF fromNode;
                    QPointF toNode;
                    fromNode.setX(nodeLocations[i].location.x());
                    fromNode.setY(nodeLocations[i].location.y());
                    toNode.setX(nodeLocations[j].location.x());
                    toNode.setY(nodeLocations[j].location.y());
                    painter->drawLine(fromNode, toNode);
                }
            }
        }
    }
    // draw cars, velocities
    painter->setBrush(QBrush(QColor::fromRgb(255,0,0, 125)));
    painter->setPen(QPen(QColor::fromRgb(0,0,0,125)));
    const QVector<car*>* cars = world->getCars();
    for(int i = 0; i < cars->size(); i++)
    {
        car* car = cars->at(i);
        QPointF pos=car->getPosition();
        //scale and rotate so that the origin is in the lower left corner
        resize(pos);
        double sizeX=4;
        double sizeY=4;
        pos.setY(size.y()-pos.y()-110);
        painter->setBrush(QBrush(car->getColor()));
        painter->drawEllipse(pos,sizeX, sizeY);
        QPointF velocity=car->getVelocity();
        resize(velocity);
        velocity.setY(-velocity.y());
        painter->drawLine(pos, pos+10*velocity);
    }
    // draw traffic lights
    const QVector<trafficlight*>* lights = world->getLights();
    for(int i=0; i < lights->size(); i++){
        if(lights->at(i)->getHorizState() == 0){
            painter->setBrush(QBrush(QColor::fromRgb(255,0,0,125)));
            painter->setPen(QPen(QColor::fromRgb(255,0,0,125)));
        }
        else if(lights->at(i)->getHorizState() == 1){
            painter->setBrush(QBrush(QColor::fromRgb(255,191,0,125)));
            painter->setPen(QPen(QColor::fromRgb(255,191,0,125)));
        }
        else {
            painter->setBrush(QBrush(QColor::fromRgb(0,255,0,125)));
            painter->setPen(QPen(QColor::fromRgb(0,255,0,125)));
        }
        painter->drawEllipse(lights->at(i)->getL(),2,2);
        painter->drawEllipse(lights->at(i)->getR(),2,2);
        if(lights->at(i)->getVertState() == 0){
            painter->setBrush(QBrush(QColor::fromRgb(255,0,0,125)));
            painter->setPen(QPen(QColor::fromRgb(255,0,0,125)));
        }
        else if(lights->at(i)->getVertState() == 1){
            painter->setBrush(QBrush(QColor::fromRgb(255,191,0,125)));
            painter->setPen(QPen(QColor::fromRgb(255,191,0,125)));
        }
        else {
            painter->setBrush(QBrush(QColor::fromRgb(0,255,0)));
            painter->setPen(QPen(QColor::fromRgb(0,255,0)));
        }
        painter->drawEllipse(lights->at(i)->getU(),2,2);
        painter->drawEllipse(lights->at(i)->getD(),2,2);
    }
    window->renderPixmap();
}
