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

    size_t bitmap = IMG_Init(IMAGE_FLAGS);
    if ((bitmap & IMAGE_FLAGS) != IMAGE_FLAGS) {
        fprintf(stderr, "error initializing SDL_image: %s\n", SDL_GetError());
        return 2;
    }

    if (TTF_Init()) {
        fprintf(stderr, "error initializing SDL_ttf: %s\n", SDL_GetError());
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
    SDL_DestroyTexture(game_graphics->text);
    TTF_CloseFont(game_graphics->font);
    SDL_DestroyTexture(game_graphics->texture);
    SDL_DestroyRenderer(game_graphics->render);
    SDL_DestroyWindow(game_graphics->window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();
    free(game_graphics);
    exit(exit_status);
}

void sdl_game_loop(graphics *game_graphics)
{
    size_t gameState = 0;
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
                        case SDL_SCANCODE_RETURN:
                            printf("YOU ENETERED THE GAME!\n");
                            gameState = 1;
                            break;
                        case SDL_SCANCODE_KP_ENTER:
                            gameState = 1;
                            printf("YOU ENTERED THE GAME FROM NUMERIC!\n");
                            break;
                        default:
                            break;
                    }
                default:
                    break;
            }
        }

        // clear
        SDL_RenderClear(game_graphics->render);
        if (gameState) {

        } else {
            // draw image
            SDL_RenderCopy(game_graphics->render, game_graphics->texture, NULL, NULL);
            // draw second image with text
            SDL_RenderCopy(game_graphics->render, game_graphics->text, NULL, &game_graphics->rect);
        }
        // present the image
        SDL_RenderPresent(game_graphics->render);
        SDL_Delay(FPS(60));
    }
}

size_t sdl_intro_screen(graphics *game_graphics)
{   
    char buff[PADDING_512], buff2[PADDING_512];
    if (!getcwd(buff, PADDING_512)) {
        perror("cannot use getcwd");
        return 2;
    }

    strcpy(buff2, buff);
    strcat(buff, "/data/images/background/background1.jpg");

    game_graphics->texture = IMG_LoadTexture(game_graphics->render, buff);
    if (!game_graphics->texture) {
        fprintf(stderr, "error creating texture: %s\n", SDL_GetError());
        return 2;
    }

    strcat(buff2, "/data/fonts/freedom.ttf");

    game_graphics->font = TTF_OpenFont(buff2, FONT_SIZE);
    if (!game_graphics->font) {
        fprintf(stderr, "error creating font: %s\n", SDL_GetError());
        return 2;
    }

    // set the font to white;
    game_graphics->font_color = (SDL_Color){255, 255, 255, 255};

    SDL_Surface *surface = TTF_RenderText_Blended(game_graphics->font, "Relam", game_graphics->font_color);
    if (!surface) {
        fprintf(stderr, "error creating surface for font: %s\n", SDL_GetError());
        return 2;
    }

    game_graphics->rect.w = surface->w;
    game_graphics->rect.h = surface->h;
    game_graphics->rect.y = (WINDOW_HEIGHT - WINDOW_WIDTH) / 2 + PIXEL_UNIT * PIXEL_UNIT;
    game_graphics->rect.x = WINDOW_WIDTH / PIXEL_UNIT;

    // this step could have been done with the image but with ttf is mandatory
    // create texture from surface
    game_graphics->text = SDL_CreateTextureFromSurface(game_graphics->render, surface);
    SDL_FreeSurface(surface);
    if (!game_graphics->text) {
        fprintf(stderr, "error creating texture from surface: %s\n", SDL_GetError());
        return 2;
    }


    return 0;
}