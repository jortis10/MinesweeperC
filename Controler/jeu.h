#ifndef JEU_HEADER
#define JEU_HEADER

#include "../Model/terrain.h"
#include "../View/view.h"

typedef struct
{
    SDL_bool key[SDL_NUM_SCANCODES]; //! contient la valeur SDL_TRUE si la touche du clavier à été appuyée, l'indice du tableau correspondant à la touche en question.
    SDL_bool quit; //!sera mis à SDL_TRUE si l'on appuie sur la croix de la fenètre
    int x, y, xrel, yrel; //! (x,y) la position absolue de la souris   (xrel,yrel) le déplacement de la souris
    SDL_bool mouse[6]; //! contient la valeur SDL_TRUE si le bouton de la souris à été préssé, l'indice du tableau correspondant à la touche en question. exemple :SDL_BUTTON_LEFT=1
} Input;


SDL_Window * init_window(int width, int height);
SDL_Renderer * init_renderer(SDL_Window* window);

void fin_partie(Terrain* terrain, SDL_Renderer * renderer);
Input init_input();
void updateEvent(Input *input);


#endif // JEU_HEADER
