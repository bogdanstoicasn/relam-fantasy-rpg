#include "load.h"

size_t sdl_initialization(graphics *game_graphics)
{
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
    
}