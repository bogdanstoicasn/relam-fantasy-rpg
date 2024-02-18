#ifndef MONSTER_H
#define MONSTER_H

#include "utils.h"
#include "skills.h"

/*
    Basic info about the monster
    See: utils.h, skills.h
*/
typedef struct {
    basic_info monster_progress;
    basic_stats monster_stats;
    skill_info monster_skills;
    monster_type monster_difficulty;
    faction_type monster_faction;
} monster_info;

#endif