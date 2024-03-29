#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_ttf.h"

#include "class.h"
#include "monster.h"
#include "player.h"

#define DIE(assertion, call_description)									\
	do {													\
		if (assertion) {										\
			fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);					\
			perror(call_description);								\
			exit(errno);										\
		}												\
	} while (0)

typedef struct database {
    class_database classes_data;
    monster_database monsters_data;
	skill_database skills_data;
} database;

typedef struct graphics {
	SDL_Window *window;
	SDL_Renderer *render;
	SDL_Texture *texture;
	SDL_Texture *text;
	TTF_Font *font;
	SDL_Color font_color;
	SDL_Rect rect;
} graphics;


#endif