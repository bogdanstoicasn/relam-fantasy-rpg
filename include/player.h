#ifndef PLAYER_H
#define PLAYER_H

#include "utils.h"
#include "skills.h"

/*
    Structure that contains player information
    See: utils.h, class.h
*/
typedef struct player_info{
    basic_info player_progress;
    size_t health;
    basic_stats player_stats;
    char player_class[PADDING_32];
    size_t skills_number;
    skill_info *skill_array;
} player_info;

size_t load_game(player_info *player_information);
void print_player_progress(player_info *player_information);

#endif