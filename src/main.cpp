#define SDL_MAIN_HANDLED
#include "SDL2/SDL.h"

int main(int argv, char** args){

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0 )
    {
        return -1;
    }
    //Crée la fenêtre SDL en taille maximisé et renvoie son pointeur
    SDL_Window* windowP = SDL_CreateWindow("",SDL_WINDOWPOS_UNDEFINED,
                                                            SDL_WINDOWPOS_UNDEFINED,
                                                            640,
                                                            480,
                                                            SDL_WINDOW_MAXIMIZED);

    SDL_DestroyWindow(windowP);
    SDL_Quit();
    return 0;
}