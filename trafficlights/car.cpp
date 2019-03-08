#include "car.h"
#include"map.h"

int inline sgn(qreal x)
{
    if(x<0) return -1;
    else return 1;
}

car::car(int startNode, int destinationNode, QColor color)
{
    car::Position = nodeLocations[startNode].location;
    car::Destination = nodeLocations[destinationNode].location;
    car::positionNode = startNode;
    car::destinationNode = destinationNode;
    car::color = color;
    // TO DO : why don't these functions return the correct thing??
 //   nextNode = paths->astar(positionNode,destinationNode);
 // nextNode = paths->dijkstras(positionNode,destinationNode);

    // initialise traffic lights
    lightVector = new QVector<trafficlight*>();
    lightVector->push_back(new trafficlight(4));
}

void car::computeNextState(QVector<car *> *cars)
 {
    Q_UNUSED(cars);
   // Q_UNUSED(paths);

    PointF tempDestination = nodeLocations[nextNode].location;

    // if sufficiently close to destination then update waypoint destination
    if(tempDestination.x()-Position.x()<2 && tempDestination.y()-Position.y()<2 ){
        nextNode = 3;
     //  nextNode = paths->dijkstras(positionNode, destinationNode);
    //   nextNode = paths->astar(positionNode, destinationNode);
        tempDestination = nodeLocations[nextNode].location;
    }
 }

 void car::Drive(){
/*
     // look at traffic lights, if close to U or D and state is red
     if(lightVector->getVertState()==0 && (Position.x()-trafficlight::getD().x()<2 && Position.y()-trafficlight::getD().y()<2 )  || (Position.x()-trafficlight::getU().x()<2 && Position.y()-trafficlight::getU().y()<2)){
         v = PointF(0,0);
     } // check L or D and horizontal state
     else if ( trafficlight::getHorizState()==0 && (Position.x()-trafficlight.getR().x()<2 && Position.y()-trafficlight.getR().y()<2 ) || (Position.x()-trafficlight.getL().x()<2 && Position.y()-trafficlight.getL().y()<2 )){
         v = PointF(0,0);
     }
    else{ */
           // move in straight line
     qreal x = (Destination.x()-Position.x());
     qreal y = (Destination.y()-Position.y());
     qreal sq = sqrt((pow(x,2)+pow(y,2)));
     PointF v = PointF(x/sq,y/sq);
     // }
     Position += v;
 }

car::~car(){

 }
