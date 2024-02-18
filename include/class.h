#ifndef CLASS_H
#define CLASS_H

#include "utils.h"

/*
    Struct that contains information about the class
    See: utils.h
*/
typedef struct {
    char class_name[PADDING_32];
    size_t class_tier;
    basic_stats class_stats;
    basic_resources class_resources;
    char class_passives[PADDING_8][PADDING_32];
} class_info;

#endif