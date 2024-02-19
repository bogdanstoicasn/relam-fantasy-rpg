#ifndef SKILLS_H
#define SKILLS_H

#include "utils.h"
#include "player.h"

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
    char description[PADDING_64];
} skill_info;

skill_info *first_class_skill(char *class, player_info *player_information);

#endif