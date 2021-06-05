#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "jeu.h"
#include "../Model/terrain.h"
#include "../Model/case.h"
#include "../View/view.h"



/**
* \fn SDL_Window * init_window()
* \brief
* Initialise une fenetre de taille 1280x1024
*
* \param[out] un pointeur sur une SDL_Window initialisée
*/
SDL_Window * init_window(int width, int height)
{
    affichage_init(SDL_INIT_VIDEO | SDL_INIT_EVENTS); //! Initialise la SDL2
    initialisation_TTF(); //! Initialise l'écriture du texte

    return createWindow("Minesweeper",SDL_WINDOWPOS_CENTERED,0,width,height,SDL_WINDOW_SHOWN);
}


/**
* \fn SDL_Renderer * init_renderer(SDL_Window* window)
* \brief
* Initialise le renderer associé à la fenetre window et affiche l'écran d'accueil pendant 2 secondes
*
* \param[in] un pointeur sur une SDL_Window initialisée
* \param[out] un pointeur sur un SDL_Renderer initialisé
*/
SDL_Renderer * init_renderer(SDL_Window* window)
{
    SDL_Renderer * renderer = createRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    //splashscreen(renderer); //! affiche l'écran d'accueil pendant 2 secondes

    return renderer;
}


/**
* \fn Input init_input()
* \brief
* Fonction qui permet d'initialiser Input
*
* \param[out] Input input : une instance d'Input avec ses attributs initialisés à SDL_FALSE
*
*/

Input init_input()
{
    Input input;
    for(int i=0; i<SDL_NUM_SCANCODES; i++)
    {
        input.key[i]=SDL_FALSE;
    }
    input.quit=0;
    input.nbpassesontour=0;
    input.retouraction=0;
    input.x=0;
    input.y=0;
    input.xrel=0;
    input.yrel=0;
    input.xwheel=0;
    input.ywheel=0;

    for(int i=0; i<6; i++)
    {
        input.mouse[i]=SDL_FALSE;
    }

    input.mouse[SDL_BUTTON_LEFT]=SDL_FALSE; //

    return input;
}


/**
* \fn void updateEvent(Input *input)
* \brief
*
* \param[in] Input *input : un pointeur sur la structure input où l'on va stocker les informations sur les périphériques
*
*/


void updateEvent(Input *input)
{
    SDL_Event event;
    SDL_WaitEvent(&event);

    if(event.type == SDL_QUIT)
        input->quit = SDL_TRUE;
    if(event.type == SDL_KEYDOWN)
        input->key[event.key.keysym.scancode] = SDL_TRUE;
    if(event.type == SDL_KEYUP&&event.key.keysym.scancode!=SDL_SCANCODE_ESCAPE) //! Condition faite pour conserver la touche echap préssée virtuellement meme apres passage dans cette fonction
        input->key[event.key.keysym.scancode] = SDL_FALSE;
    if(event.type == SDL_MOUSEMOTION)
    {
        input->x = event.motion.x;
        input->y = event.motion.y;
        input->xrel = event.motion.xrel;
        input->yrel = event.motion.yrel;
    }
    if(event.type == SDL_MOUSEWHEEL)
    {
        input->xwheel = event.wheel.x;
        input->ywheel = event.wheel.y;
    }
    if(event.type == SDL_MOUSEBUTTONDOWN)
        input->mouse[event.button.button] = SDL_TRUE;
    if(event.type == SDL_MOUSEBUTTONUP)
        input->mouse[event.button.button] = SDL_FALSE;
}

/**
* \fn void fin_partie(Partie *partie, SDL_Renderer * renderer)
* \brief Gère la fin de partie
*
* \param[in] Partie *partie, SDL_Renderer * renderer
*
*/

void fin_partie(Terrain *terrain, SDL_Renderer * renderer)
{

    //! Affichage de l'écran des scores
    SDL_Delay(5000);

}
