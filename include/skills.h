#ifndef SKILLS_H
#define SKILLS_H

#include "utils.h"


/*
    Contains info about the skill
    See: utils.h
*/
typedef struct skill_info {
    basic_info skill_progress;
    enum skill_type skill_damage_type;
    enum skill_subtype skill_modifier;
    penetration skill_penetration;
    size_t strikes;
    size_t turns;
    char description[PADDING_64];
} skill_info;

/*
    Generates the first skill of the class the player chooses
*/
skill_info *first_class_skill(char *class);

/*
    Puts a string in the progress file.
    The file must already be opened.
*/
void skill_print_function(FILE *fptr, skill_info *skill_data);

#endif