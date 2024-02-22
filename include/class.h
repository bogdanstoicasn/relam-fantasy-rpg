#ifndef CLASS_H
#define CLASS_H

#include "utils.h"
typedef struct database database;
/*
    Struct that contains information about the class
    See: "utils.h"
*/
typedef struct class_info {
    char class_name[PADDING_128];
    size_t class_tier;
    basic_stats class_stats;
    size_t passives;
    char class_passives[PADDING_8][PADDING_128];
} class_info;

/*
    Struct that contains the number of classes in the game and the
    classes themselves
    See: "utils.h"
*/
typedef struct class_database {
    size_t number;
    class_info *classes;
} class_database;

char *first_class_choosing_function();
void read_class_data(database *gamedata, FILE *fptr);
void print_all_classes(class_database data);

#endif