#ifndef SKILLS_H
#define SKILLS_H

#include "utils.h"

/*
    Contains info about the skill
    See: utils.h
*/
typedef struct {
    basic_info skill_progress;
    skill_type skill_damage;
    skill_subtype skill_modifier;
    penetration skill_penetration;
    size_t skill_strikes;
} skill_info;

#endif