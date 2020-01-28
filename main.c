/**
    ************* Welcome to the BULLTRICKER game *****************
                         ©opyRight 2019
**/

#include    "./include/controle.h"
#include    "./include/gui.h"
#include    "./include/route.h"


int main(int argc, char* argv[]){
    

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Initialize SDL: %s",
                     SDL_GetError());
        return 0;
    }

    if (SDL_CreateWindowAndRenderer(WINDOW_WEIGHT, WINDOW_LENGTH, 0, &window,
                                    &renderer) < 0) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION,
                     "Create window and renderer: %s", SDL_GetError());
        return 0;
    }
    SDL_Surface *icon = IMG_Load("public/bullT.ico");

    SDL_SetWindowIcon(window,icon);
    SDL_SetWindowTitle(window, GAME_NAME);
    
    __Route(renderer);

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_QuitSubSystem(SDL_INIT_EVERYTHING);
    atexit(SDL_Quit);

    return 0;
}