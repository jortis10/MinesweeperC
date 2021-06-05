#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdio.h>
#include <stdlib.h>


#include "../Model/terrain.h"


static int setup_zero(void **state)
{
    Terrain *t = initTerrain();
    if(t == NULL)
    {
        printf("error mem in setup_zero of initTerrain\n");
        return -1;
    }
    *state = t;

    return 0;
}

static void test_videTerrain(void **state){
    Terrain *t=(Terrain *) (*state);

    videTerrain(t);

    for(int x = 0; x < t->x_size; x++){
        for (int y = 0; y < t->y_size; y++){
            assert_int_equal(CLOSE,t->cases[x][y]->state);
            assert_int_equal(EMPTY,t->cases[x][y]->type);
        }
    }

}

static int teardown(void **state)
{
    freeTerrain(*state);
    return 0;
}

int main_test_plateau(void)
{
    const struct CMUnitTest test_terrain[] =
    {
        cmocka_unit_test_setup_teardown(test_videTerrain,setup_zero,teardown),

    };
    return cmocka_run_group_tests(test_terrain,NULL,NULL);
}

