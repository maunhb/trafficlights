#include "smartlight.h"

smartlight::smartlight()
{

}

void smartlight::change_lights_vert( QVector<trafficlight*>* lightVector, QVector<stats*>* statVector){
    //  GIVE THESE SOME LOGIC
  /*  for(int i=0; i<lightVector->size(); i++){
        if(start_time % 50 == 0){
            lightVector->at(i)->vert_state == 2;
        }
    }*/
    if(statVector->last()->num_waiting > 3 ){
      lightVector->at(0)->vert_state =  (lightVector->at(0)->vert_state = 0) ;
      lightVector->at(0)->horiz_state =  (lightVector->at(0)->horiz_state = 2) ;
    }
    // change num_waiting into horiz and vertical waiting and do it for each light
}

void smartlight::change_lights_horiz(QVector<trafficlight*>* lightVector,QVector<stats*>* statVector){
 /*   if(statVector->last()->num_waiting > 4 ){
      lightVector->at(0)->horiz_state =  (lightVector->at(0)->horiz_state += 1) % 2;
    } */
}
