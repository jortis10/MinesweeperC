/**
* \file affichage_sdl.c
*
* \brief Fichier contenant le code nécessaire à l'affichage graphique (SDL2) du programme
*
* \author JENNY Thibaud & SOW Aicha
* \version 2.0
* \date 10/05/2020
*
* Dans ce fichier se trouve le code des fonctions de l'interface graphique
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "view.h"


/**
* \fn int affichage_init(int flag)
* \brief initialisation de la bibliotheque SDL2 avec les flags d'initialisation
* \param[in] int flag
* \param[out] int EXIT_FAILURE si erreur , EXIT_SUCCESS sinon
*/


int affichage_init(int flag)
{

    if(SDL_Init(flag)!= 0)
    {

        fprintf(stderr,"Erreur SDL_Init : %s\n",SDL_GetError());
        SDL_Log("Init SDL : Failure\n");
        SDL_Quit();
        return EXIT_FAILURE;
    }
    SDL_Log("Init SDL2 : Success\n");
    return EXIT_SUCCESS;
}


/**
* \fn int initialisation_TTF(void)
* \brief initialisation de la bibliotheque SDL2_ttf
* \param[in] none
* \param[out] int EXIT_FAILURE si erreur , EXIT_SUCCESS sinon
*/


int initialisation_TTF(void)
{
    if(!TTF_WasInit() && TTF_Init()==-1)
    {
        fprintf(stderr,"Erreur TTF_Init : %s\n",TTF_GetError());
        SDL_Log("Init TTF : Failure\n");
        TTF_Quit();
        return EXIT_FAILURE;
    }
    SDL_Log("Init TTF: Success\n");
    return EXIT_SUCCESS;

}


/**
* \fn SDL_Window* createWindow(char* titre, int flag1, int flag2,int largeur,int hauteur,int flag3)
* \brief la fonction permet de creer une fenetre graphique avec les flags requis
* \param[in] char* titre, int flag1, int flag2,int largeur,int hauteur,int flag3
* \param[out] SDL_Window* window
*/


SDL_Window* createWindow(char* titre, int flag1, int flag2,int largeur,int hauteur,int flag3)
{
    SDL_Window *window = SDL_CreateWindow(titre,flag1,flag2,largeur,hauteur,flag3);

    if(window == NULL)
    {
        fprintf(stderr,"Erreur SDL_createWindow : %s\n",SDL_GetError());
        SDL_Log("Create Window : Failure\n");
        SDL_DestroyWindow(window);
        return NULL;
    }
    SDL_Log("Create Window : Success\n");
    return window;
}


/**
* \fn SDL_Renderer* createRenderer(SDL_Window* window,int index,int flag)
* \brief la fonction permet de creer le renderer de la fenetre window
* \param[in] SDL_Window* window,int index,int flag
* \param[out] SDL_Renderer* renderer
*/


SDL_Renderer* createRenderer(SDL_Window* window,int index,int flag)
{
    SDL_Renderer *renderer = SDL_CreateRenderer(window,index,flag);
    if(renderer == NULL)
    {
        fprintf(stderr,"Erreur SDL_createRender: %s\n",SDL_GetError());
        SDL_Log("Create Renderer : Failure\n");
        SDL_DestroyRenderer(renderer);
        return NULL;
    }
    SDL_Log("Create Renderer : Sucess\n");
    return renderer;
}


/**
* \fn void affichage_pause(int delay)
* \brief la fonction permet de mettre le programme en pause
* \param[in] int delay // temps de pause en ms
* \param[out] none
*/


void affichage_pause(int delay)
{
    SDL_Log("Delay of %d s\n",delay/1000);
    SDL_Delay(delay);
}


/**
* \fn SDL_Texture* createTexture(SDL_Renderer* renderer,SDL_Surface* surface)
* \brief la fonction permet de creer une texture a partir d'une surface
* \param[in] SDL_Renderer* renderer,SDL_Surface* surface
* \param[out] SDL_Texture* texture
*/


SDL_Texture* createTexture(SDL_Renderer* renderer,SDL_Surface* surface)
{

    SDL_Texture* texture = NULL;
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    SDL_FreeSurface(surface);                                           //affichage_destroy(NULL,NULL,surface,NULL)
    if(NULL == texture)
    {
        fprintf(stderr, "Erreur SDL_CreateTextureFromSurface : %s", SDL_GetError());
        SDL_Log("Create Texture : Failure\n");
        SDL_DestroyTexture(texture);
        return NULL;
    }
    SDL_Log("Create Texture : Success \n");

    return texture;

}


/**
* \fn SDL_Texture* loadImage(SDL_Renderer* renderer,char* image)
* \brief la fonction permet de charger une image BMP
* \param[in] SDL_Renderer* renderer,char* image
* \param[out] SDL_Texture* texture
*/


SDL_Texture* loadImage(SDL_Renderer* renderer,char* image)
{
    SDL_Surface* surface_img = NULL;
    surface_img = SDL_LoadBMP(image);

    if(NULL == surface_img)
    {
        fprintf(stderr, "Erreur SDL_LoadBMP : %s", SDL_GetError());
        SDL_Log("Load Bitmap %s : Failure\n",image);
        SDL_FreeSurface(surface_img);
        return NULL;
    }
    SDL_Texture* texture =createTexture(renderer,surface_img);

    if(NULL!=texture)
    {
        SDL_Log("Load %s : Success\n",image);
    }
    return texture;
}


/**
* \fn SDL_Rect createFraming(int width, int height, int x,int y)
* \brief la fonction permet d'avoir le framing ou delimitation
       afin de restreindre l'ecriture d'un texte ou l'affiche d'une image au framing souhaité
* \param[in] int width, int height, int x,int y
* \param[out] SDL_Rect framing
*/


SDL_Rect createFraming(int width, int height, int x,int y)
{
    SDL_Rect framing;

    framing.w =width;
    framing.h =height;
    framing.x=x;
    framing.y=y;

    return framing;
}

/**
* \fn void affichageEcran(SDL_Renderer* renderer,char* imagedefond)
* \brief la fontion permet d'afficher l'image de fond du jeu
* \param[in] SDL_Renderer* renderer,char* imagedefond
* \param[out] none
*/


void affichageEcran(SDL_Renderer* renderer,char* imagedefond)
{
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Texture* texture_main = loadImage(renderer,imagedefond);
    SDL_RenderCopy(renderer,texture_main,NULL,NULL);
    SDL_RenderPresent(renderer);
    SDL_DestroyTexture(texture_main);


}


/**
* \fn void splashscreen(SDL_Renderer *renderer)
* \brief La fonction permet de gerer l'affichage au démarrage du jeu
* \param[in] SDL_Renderer *renderer
* \param[out] none
*/


void splashscreen(SDL_Renderer *renderer)
{
    SDL_Texture * texture = loadImage(renderer,"res/qwirkle.bmp");
    SDL_Texture* bottom_splash_texture = loadImage(renderer,"res/bottom.bmp");

    SDL_Rect dst1;
    SDL_Rect dst2;
    dst1.h = HEIGHT/1.4;
    dst1.w = WIDTH/1.2;
    dst1.x = (WIDTH/2 - dst1.w/2);
    dst1.y = (HEIGHT/2 - dst1.h/2);

    dst2.h = HEIGHT/10;
    dst2.w = WIDTH/5;
    dst2.x=(WIDTH/2 - dst2.w/2);
    dst2.y=HEIGHT-dst2.h;

    SDL_SetRenderDrawColor(renderer,255,255,255,SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer,bottom_splash_texture,NULL,&dst2);
    SDL_RenderCopy(renderer,texture,NULL,&dst1);
    SDL_RenderPresent(renderer);

    affichage_pause(2000);

    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(bottom_splash_texture);
}


/**
* \fn TTF_Font* setPolice(char* font, int tailledepolice)
* \brief la fontion permet de definir une police d'ecriture (font + taille)
*
* \param[in] char* font, int tailledepolice // le style d'ecriture (font) et la taille du texte
* \param[out] TTF_Font*  police // la police d'ecriture
*/


TTF_Font* setPolice(char* font, int tailledepolice)
{
    TTF_Font *police=NULL;
    police = TTF_OpenFont("res/arial.ttf",tailledepolice);
    if(NULL==police)
    {
        fprintf(stderr,"Erreur d'ouverture du font: %s\n",TTF_GetError());
        SDL_Log("TTF Openfont : Failure\n");
        TTF_CloseFont(police);
        return NULL;
    }

    SDL_Log("TTF Openfont : SUCCESS\n");
    return police;

}


/**
* \fn int writeThis(SDL_Renderer* renderer,SDL_Texture* textureTexte,TTF_Font *police, char* texte, SDL_Color couleurTexte, SDL_Rect* encadrementtexte)
* \brief La fonction permet d'ecrire un texte sur le rendu
* \param[in]  SDL_Renderer* renderer
* \param[in]  SDL_Texture* textureTexte  // la texture sur laquelle ecire
* \param[in]  TTF_Font *police   // la police d'ecriture du texte
* \param[in]  char* texte   // le texte a ecrire
* \param[in]  SDL_Color couleurTexte   // la couleur du texte
* \param[in]  SDL_Rect* encadrementtexte   // le framing du texte
*
* \param[out] int -1 si erreur 0 sinon
*/


int writeThis(SDL_Renderer* renderer,SDL_Texture* textureTexte,TTF_Font *police, char* texte, SDL_Color couleurTexte, SDL_Rect* encadrementtexte)
{
    SDL_Surface*surfaceTexte=NULL;
    surfaceTexte=TTF_RenderText_Blended(police,texte,couleurTexte);

    if(NULL==surfaceTexte)
    {
        fprintf(stderr,"Erreur renderText: %s\n",TTF_GetError());
        SDL_Log("creation de surfaceTexte: Failure\n");
        SDL_FreeSurface(surfaceTexte);
        return -1;
    }
    SDL_Log("TTF_RenderText_Blended : SUCCESS\n");

    textureTexte = createTexture(renderer,surfaceTexte);
    if(NULL!=textureTexte)
    {
        SDL_Log("Ecriture de texte: SUCCESS\n");
    }
    SDL_RenderCopy(renderer,textureTexte,NULL,encadrementtexte);
    return 0;
}



