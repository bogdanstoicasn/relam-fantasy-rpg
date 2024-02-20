#ifndef CLASS_H
#define CLASS_H

#include "utils.h"

/*
    Struct that contains information about the class
    See: utils.h
*/
typedef struct class_info {
    char class_name[PADDING_32];
    size_t class_tier;
    basic_stats class_stats;
    size_t health;
    char class_passives[PADDING_8][PADDING_32];
} class_info;

char *first_class_choosing_function();

#endif