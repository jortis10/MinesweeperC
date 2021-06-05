#ifndef TERRAIN_HEADER
#define TERRAIN_HEADER

#include "case.h"

#define MAXSIZE 200

typedef struct{

    int x_size;
    int y_size;
    Case* cases[MAXSIZE][MAXSIZE];

}Terrain;



Terrain* initTerrain();
void freeTerrain(Terrain *p);

void videTerrain(Terrain *p);


#endif // CASE_HEADER
