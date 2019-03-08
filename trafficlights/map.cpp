#include "map.h"

map::map()
{
    tiles[0].inter=0; tiles[0].horiz=0; tiles[0].vert=0;
    tiles[1].inter=0; tiles[1].horiz=0; tiles[4].vert=1;
    tiles[2].inter=0; tiles[2].horiz=0; tiles[2].vert=0;
    tiles[3].inter=0; tiles[3].horiz=1; tiles[3].vert=0;
    tiles[4].inter=1; tiles[4].horiz=1; tiles[4].vert=1;
    tiles[5].inter=0; tiles[5].horiz=1; tiles[5].vert=0;
    tiles[6].inter=0; tiles[6].horiz=0; tiles[6].vert=0;
    tiles[7].inter=0; tiles[7].horiz=0; tiles[7].vert=1;
    tiles[8].inter=0; tiles[8].horiz=0; tiles[8].vert=0;
    /* if(num_intersections==1)
    {
    tiles[0].inter=0; tiles[0].horiz=0; tiles[0].vert=0;
    tiles[1].inter=0; tiles[1].horiz=0; tiles[4].vert=1;
    tiles[2].inter=0; tiles[2].horiz=0; tiles[2].vert=0;
    tiles[3].inter=0; tiles[3].horiz=1; tiles[3].vert=0;
    tiles[4].inter=1; tiles[4].horiz=1; tiles[4].vert=1;
    tiles[5].inter=0; tiles[5].horiz=1; tiles[5].vert=0;
    tiles[6].inter=0; tiles[6].horiz=0; tiles[6].vert=0;
    tiles[7].inter=0; tiles[7].horiz=0; tiles[7].vert=1;
    tiles[8].inter=0; tiles[8].horiz=0; tiles[8].vert=0;
    } */
   /* if (num_intersections==2){

       };
   }; */

}
