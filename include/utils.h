#ifndef UTILS_H
#define UTILS_H

#include <stddef.h>

#define MAX_SKILLS 21
#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))


#define PADDING_1024 1024
#define PADDING_256 256
#define PADDING_128 128
#define PADDING_64 64
#define PADDING_32 32
#define PADDING_8 8

#define DIE(assertion, call_description)									\
	do {													\
		if (assertion) {										\
			fprintf(stderr, "(%s, %d): ", __FILE__, __LINE__);					\
			perror(call_description);								\
			exit(errno);										\
		}												\
	} while (0)

/*
    Basic information about character/boss
    Made it in a struct to be more compact
*/
typedef struct {
    char name[32];
    size_t level;
    unsigned long long exp;
} basic_info;

/*
    Basic stats of a character/monsters
*/
typedef struct {
    size_t attack;
    size_t magic;
    size_t defense;
    size_t resistance;
    size_t dodge;
} basic_stats;

/*
    Penetration types
*/
typedef struct {
    float p1;
    float p2;
    float p3;
} penetration;

/*
    Skill types
    We can add more types later
*/
enum skill_type {
    ATTACK = 0,
    MAGIC = 1,
    BUFF = 2,
    DEBUFF = 3
};

/*
    Skill subtype
    We can add more subtypes later for complex mechanics
*/
enum skill_subtype {
    BLUNT = 0,
    EDGE = 1,
    ELEMENTAL = 2,
    ARCANE = 3
};

/*
    Basic monster types
*/
enum monster_type {
    NORMAL = 0,
    BERSERK = 1,
    BOSS = 2,
    BERSERK_BOSS = 3
};

/*
    Factions
*/
enum faction_type {
    HUMAN = 0,
    BEAST = 1
};

#endif