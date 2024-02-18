#ifndef SKILLS_H
#define SKILLS_H

#include "utils.h"

/*
    Contains info about the skill
    See: utils.h
*/
typedef struct skill_info {
    basic_info skill_progress;
    enum skill_type skill_damage;
    enum skill_subtype skill_modifier;
    penetration skill_penetration;
    size_t skill_strikes;
} skill_info;

#endif