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
 //   qDebug() << Position;
    car::Destination = nodeLocations[destinationNode].location;
 //   qDebug() << Destination ;
    car::positionNode = startNode;
    car::destinationNode = destinationNode;
    car::color = color;
    car::horiz_close = 0;
    car::vert_close = 0;
    car::wait = 0;
    Ini();
    // TO DO : why don't these functions return the correct thing??
 //   nextNode = paths->astar(positionNode,destinationNode);
 // nextNode = paths->dijkstras(positionNode,destinationNode);

/*    // initialise traffic lights
    lightVector = new QVector<trafficlight*>();
    lightVector->push_back(new trafficlight(4)); */
}

void car::closeTrafficLight(QVector<trafficlight*> *lights){
    for( int i = 0; i < lights->size(); i++){
        // close to D?
        if( Position.y() - lights->at(i)->positionD.y()<spacing && lights->at(i)->positionD.y() - Position.y() <spacing)
        { vert_close = 1;}
        // close to U?
        else if( Position.y() - lights->at(i)->getU().y()<spacing && Position.y() - lights->at(i)->getU().y()>-spacing )
         { vert_close = 1;}
        // close to L?
        else if( Position.x() - lights->at(i)->getL().x()<spacing && Position.x() - lights->at(i)->getL().x()>-spacing )
        { horiz_close = 1;}
        // close to R?
        else if( Position.x() - lights->at(i)->getR().x()<spacing && Position.x() - lights->at(i)->getR().x()>-spacing )
         { horiz_close = 1;}
    }
}

void car::closeCar(QVector<car*> *cars){
    // if you are not waiting look for traffic jam
    if(wait == 0){
        // is the car infront already waiting?
        qreal x = (Destination.x()-Position.x());
        qreal y = (Destination.y()-Position.y());
        qreal sq = sqrt((pow(x,2)+pow(y,2)));
        PointF v = PointF(2*x/sq,2*y/sq);
        for( int i = 0; i < cars->size(); i++){
            if(cars->at(i)->wait == 1){
                if((Position+v).x()-cars->at(i)->getPosition().x() < spacing && (Position+v).x()-cars->at(i)->getPosition().x() > -spacing && (Position+v).y()-cars->at(i)->getPosition().y() < spacing && (Position+v).y()-cars->at(i)->getPosition().y() > -spacing){
                    wait = 1;
                    break;
                }
            }
            if(i == cars->size()){
                // if no cars were waiting then neither should you
                wait = 0;
            }
        }
    }
}

void car::computeNextState(QVector<car *> *cars, QVector<trafficlight*> *lights)
 {
    Q_UNUSED(cars);
   // Q_UNUSED(paths);
    for( int i = 0; i < lights->size(); i++){
        // look at traffic lights, if close to U or D and state is red
        if(vert_close == 1 ){
            if(lights->at(i)->getVertState()==0){
                wait = 1;
            }
            else {
                wait = 0;
            }
        }
        // look at traffic lights, if close to U or D and state is red
        else if(horiz_close == 1 ){
            if(lights->at(i)->getHorizState()==0){
                wait = 1;
            }
            else {
                wait = 0;
            }
        }
    }

    /*
    PointF tempDestination = nodeLocations[nextNode].location;

    // if sufficiently close to destination then update waypoint destination
    if(tempDestination.x()-Position.x()<2 && tempDestination.y()-Position.y()<2 ){
        nextNode = 3;
     //  nextNode = paths->dijkstras(positionNode, destinationNode);
    //   nextNode = paths->astar(positionNode, destinationNode);
        tempDestination = nodeLocations[nextNode].location;
    } */

 }

 void car::Drive(){
     PointF v;
     if(wait == 1){
         // no movement
         v = PointF(0,0);
     }
     else{     // move in straight line
        qreal x = (Destination.x()-Position.x());
        qreal y = (Destination.y()-Position.y());
        qreal sq = sqrt((pow(x,2)+pow(y,2)));
        v = PointF(x/sq,y/sq);
      }
     Position += v;

 /*    qDebug() << x;
     qDebug() << y;
     qDebug()<< sq ; */
 }

car::~car(){

 }
