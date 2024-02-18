#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"

/*
    Structure that contains player information
    See: utils.h, class.h
*/
typedef struct player_info{
    basic_info player_progress;
    basic_resources player_resources;
    basic_stats player_stats;
    char player_class[PADDING_32];
    char player_skills[MAX_SKILLS][PADDING_32];
} player_info;

#endif