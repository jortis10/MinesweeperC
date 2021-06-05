#include <stdio.h>
#include <stdlib.h>
#include "Model/terrain.h"
#include "Controler/jeu.h"

int main()
{


    /*! Initialisation des données du Modèle */
    Terrain* terrain = initTerrain(10,10);

    /*! Initialisation de l'affichage */
    SDL_Window * window = init_window(800,600);
    SDL_Renderer * renderer =init_renderer(window);

     /*! Initialisation de la structure stockant l'état des périphériques */
    Input input=init_input();

    affichage_pause(10000);

    /*! Début de la routine de jeu */

    /*! Libération de la mémoire allouée une fois que le joueur à decider de quitter le jeu Qwirkle et fin de partie*/


    freeTerrain(terrain);

    return 0;
}
