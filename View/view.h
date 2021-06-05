#ifndef VIEW_HEADER
#define VIEW_HEADER

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#define DELAY 7000
#define HEIGHT 1024
#define WIDTH 1280


int affichage_init(int flag);
SDL_Window* createWindow(char* titre, int flag1, int flag2,int hauteur,int largeur,int flag3);
SDL_Renderer* createRenderer(SDL_Window* window,int index,int flag);
void affichage_pause(int delay);
SDL_Texture* loadImage(SDL_Renderer* renderer,char* image);
void splashscreen(SDL_Renderer *renderer);
int initialisation_TTF(void);
SDL_Texture* createTexture(SDL_Renderer* renderer,SDL_Surface* surface);
TTF_Font* setPolice(char* font, int tailledepolice);
int writeThis(SDL_Renderer* renderer,SDL_Texture* textureTexte,TTF_Font *police, char* texte, SDL_Color couleurTexte, SDL_Rect* encadrementtexte);
SDL_Rect createFraming(int width, int height, int x,int y);



#endif // VIEW_HEADER
