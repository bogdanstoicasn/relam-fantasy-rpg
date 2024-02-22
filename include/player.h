#ifndef PLAYER_H
#define PLAYER_H

#include "skills.h"

/*
    Structure that contains player information
    See: "utils.h", "class.h"
*/
typedef struct player_info{
    basic_info player_progress;
    size_t free_points;
    basic_stats player_stats;
    char player_class[PADDING_32];
    size_t skills_number;
    skill_info *skill_array;
} player_info;

void create_player_file(char *progress_file);

void read_player_progress(player_info *player_information, FILE *fptr);
void print_player_progress(player_info *player_information);

#endif