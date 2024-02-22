#ifndef MONSTER_H
#define MONSTER_H

#include "skills.h"
typedef struct database database;
/*
    Basic info about the monster
    See: utils.h, skills.h
*/
typedef struct monster_info{
    basic_info monster_progress;
    basic_stats monster_stats;
    enum monster_type monster_difficulty;
    enum faction_type monster_faction;
    size_t skill_number;
    skill_info *monster_skills;
} monster_info;

typedef struct monster_database {
    size_t number;
    monster_info *monsters;
} monster_database;

void read_monster_data(database *game_database, FILE *fptr);
void print_all_monsters(monster_database data);

#endif