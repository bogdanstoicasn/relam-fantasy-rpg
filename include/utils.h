#ifndef UTILS_H
#define UTILS_h

#include <stddef.h>

#define MAX_SKILLS 24
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
    char s[32];
    size_t level;
    unsigned long long exp;
} basic_info;

/*
    Basic resources of a character/monster
*/
typedef struct {
    size_t health;
    size_t mana;
} basic_resources;

/*
    Basic stats of a character/monsters
*/
typedef struct {
    size_t attack;
    size_t magic;
    size_t defensive;
    size_t resistance;
    size_t dodge;
} basic_stats;

/*
    Penetration types
*/
typedef struct {
    float p1;
    float p2;
} penetration;

/*
    Skill types
    We can add more types later
*/
enum skill_type {
    ATTACK,
    MAGIC,
    BUFF,
    DEBUFF
};

/*
    Skill subtype
    We can add more subtypes later for complex mechanics
*/
enum skill_subtype {
    BLUNT,
    EDGE,
    ELEMENTAL
};

/*
    Basic monster types
*/
enum monster_type {
    NORMAL,
    BERSERK,
    BOSS,
    BERSERK
};

/*
    Factions
*/
enum faction_type {
    HUMAN,
    BEAST
};

#endif