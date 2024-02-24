#include "graphics.h"

/*
    Initialization of the SDL2 lib
*/
size_t sdl_initialization(graphics *game_graphics)
{
    if (SDL_Init(SDL_INIT_EVERYTHING)) {
        fprintf(stderr, "error initializing SDL: %s\n", SDL_GetError());
        return 2;
    }

    game_graphics->window = SDL_CreateWindow(WINDOW_NAME,
    SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, 0);

    if (!game_graphics->window) {
        fprintf(stderr, "error creating window: %s\n", SDL_GetError());
        return 2;
    }

    game_graphics->render = SDL_CreateRenderer(game_graphics->window, -1, 0);

    if (!game_graphics->render) {
        fprintf(stderr, "error creating renderer: %s\n", SDL_GetError());
        return 2;
    }

    return 0;
}
/*
    Clean all the sdl resources 
    Free the adynamically allocated struct that points to the resources
*/
void sdl_cleanup(graphics *game_graphics, size_t exit_status)
{
    SDL_DestroyRenderer(game_graphics->render);
    SDL_DestroyWindow(game_graphics->window);
    SDL_Quit();
    free(game_graphics);
    exit(exit_status);
}

void game_loop(graphics *game_graphics)
{
    while(1) {
        
        /* gets all the events*/
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    return;
                case SDL_KEYDOWN:
                //if press escape u exit
                // SDLK_ESCAPE DOESNT WORK
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            return;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }

        SDL_RenderClear(game_graphics->render);
        SDL_RenderPresent(game_graphics->render);
        SDL_Delay(FPS(60));
    }
}