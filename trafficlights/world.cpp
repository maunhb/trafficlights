#include "world.h"
#include"initialise.h"

World::World(QPointF size){
    maxX=450;
    maxY=450;
    World::size = size;
    carsVector = new QVector<car*>();
    lightVector = new QVector<trafficlight*>();
    carspace = 0;
  //  paths = new pathfinder;

   // initialise cars, lights:
    InitialiseWorld(this, carsVector, lightVector);
}

void World::computeIteration(double dTime){
    // remove cars who have reached their destination
    for(int i=0; i < carsVector->size(); i++)
    {
        if(carsVector->at(i)->getPosition().x() - carsVector->at(i)->getDestination().x() < 1e-9 && carsVector->at(i)->getPosition().x() - carsVector->at(i)->getDestination().x() > -1e-9 && carsVector->at(i)->getPosition().y() - carsVector->at(i)->getDestination().y() < 1e-9 && carsVector->at(i)->getPosition().y() - carsVector->at(i)->getDestination().y() > -1e-9)
        {
            delete carsVector->at(i);
            carsVector->erase(carsVector->begin()+i);
        }
    }
    Q_UNUSED(dTime);
    // let cars calculate moves
    for(int i = 0; i < carsVector->size() ; i++){
        carsVector->at(i)->closeTrafficLight(lightVector);
        carsVector->at(i)->closeCar(carsVector);
        carsVector->at(i)->computeNextState(carsVector, lightVector);

    }
    for(int i = 0; i < carsVector->size() ; i++){
        carsVector->at(i)->Drive();
    }
    // randomly generate cars
    carspace += 1;
    if(carspace%4 == 0){
        double r = ((double) rand() / (RAND_MAX));
        if(r < 0.05){
            carsVector->push_back(new car(0,5));
        }
        else if(r>0.95){
            carsVector->push_back(new car(9,2));
        }
        r = ((double) rand() / (RAND_MAX));
        if(r < 0.05){
            carsVector->push_back(new car(3,8));
        }
        else if(r>0.95){
            carsVector->push_back(new car(6,11));
        }
        num_waiting = 0;
        for(int i=0; i<carsVector->size(); i++){
            if(carsVector->at(i)->wait == 1){
                num_waiting +=1;
            }
        }
        qDebug() << "waiting" ;
        qDebug() << num_waiting;
    }
}
