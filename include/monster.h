#ifndef MONSTER_H
#define MONSTER_H

#include "skills.h"

/*
    Basic info about the monster
    See: utils.h, skills.h
*/
typedef struct monster_info{
    basic_info monster_progress;
    basic_stats monster_stats;
    size_t skill_number;
    skill_info monster_skills;
    enum monster_type monster_difficulty;
    enum faction_type monster_faction;
} monster_info;

typedef struct monster_database {
    size_t number;
    monster_info *classes;
} monster_database;

#endif