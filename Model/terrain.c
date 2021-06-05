#include <stdlib.h>
#include "terrain.h"


Terrain * initTerrain(int x_size, int y_size)
{
    Terrain *t=(Terrain*)malloc(sizeof(Terrain));
    if (t == NULL)
    {
        return NULL;
    }


    for(int x = 0; x < x_size; x++)
    {
        for(int y = 0; y < y_size; y++)
        {
            t->cases[x][y]=NULL;

        }
    }

    t->x_size = x_size;
    t->y_size = y_size;

    return t;
}

void videTerrain(Terrain *t){
    for(int x = 0; x < t->x_size; x++)
    {
        for(int y = 0; y < t->y_size; y++)
        {
            t->cases[x][y]->state = CLOSE;
            t->cases[x][y]->type = EMPTY;

        }
    }

}



void freeTerrain(Terrain *t)
{
    if(t!=NULL)
    {
        free(t);
    }

}
