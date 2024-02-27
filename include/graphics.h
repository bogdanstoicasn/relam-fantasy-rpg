#ifndef GRAPHICS_H
#define GRAPHICS_H

#include "library.h"

#define WINDOW_NAME "Relam Rpg"
#define WINDOW_WIDTH 360
#define WINDOW_HEIGHT 800
#define PIXEL_UNIT 10

#define FPS(fps_value) (1000 / (fps_value))

#define IMAGE_FLAGS IMG_INIT_JPG

#define FONT_SIZE 80

size_t sdl_initialization(graphics *game_graphics);
void sdl_cleanup(graphics *game_graphics, size_t exit_status);
void sdl_game_loop(graphics *game_graphics);
size_t sdl_intro_screen(graphics *game_graphics);

#endif // GRAPHICS_H