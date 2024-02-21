#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "class.h"
#include "monster.h"
#include "player.h"

#define DIE(assertion, call_description)									\
	do {													\
		if (assertion) {										\
			fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);					\
			perror(call_description);								\
			exit(errno);										\
		}												\
	} while (0)

typedef struct database {
    class_database *classes_data;
    monster_database *monsters_data;
    skill_database *attack_skills;
    skill_database *magic_skills;
} database;

#endif