#include "load.h"

// MONSTER UTILITIES
/*
    Loads the monsters in the database

*/
void read_monster_data(database *game_database, FILE *fptr)
{
    char buff[PADDING_128];

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
    size_t number = atoi(buff);

    game_database->monsters_data.number = number;
    game_database->monsters_data.monsters = malloc(sizeof(monster_info) * number);

    for (size_t i = 0; i < number; ++i) {
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Name: %[^\n]", game_database->monsters_data.monsters[i].monster_progress.name);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Level: %ld", &game_database->monsters_data.monsters[i].monster_progress.level);
    
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Exp: %lld", &game_database->monsters_data.monsters[i].monster_progress.exp);
        
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Health: %ld", &game_database->monsters_data.monsters[i].monster_stats.health);
        
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Attack: %ld", &game_database->monsters_data.monsters[i].monster_stats.attack);
        
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Magic: %ld", &game_database->monsters_data.monsters[i].monster_stats.magic);
        
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Defense: %ld", &game_database->monsters_data.monsters[i].monster_stats.defense);
        
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Resistance: %ld", &game_database->monsters_data.monsters[i].monster_stats.resistance);
        
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Dodge: %ld", &game_database->monsters_data.monsters[i].monster_stats.dodge);
        
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Type: %d", (int *)&game_database->monsters_data.monsters[i].monster_difficulty);
        
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Faction: %d", (int *)&game_database->monsters_data.monsters[i].monster_faction);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading monster data");
        sscanf(buff, "Monster Skills: %ld", &game_database->monsters_data.monsters[i].skill_number);

        size_t skill_number = game_database->monsters_data.monsters[i].skill_number;
        game_database->monsters_data.monsters[i].monster_skills = malloc(sizeof(skill_info) * skill_number);
        if (!game_database->monsters_data.monsters[i].monster_skills)
            DIE(1, "Memory allocation failed");
        for (size_t j = 0; j < skill_number; ++j) {
            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Skill Name: %[^\n]", game_database->monsters_data.monsters[i].monster_skills[j].skill_progress.name);

            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Skill Level: %ld", &game_database->monsters_data.monsters[i].monster_skills[j].skill_progress.level);
            
            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Skill Exp: %lld", &game_database->monsters_data.monsters[i].monster_skills[j].skill_progress.exp);
            
            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Skill Type: %d", (int *)&game_database->monsters_data.monsters[i].monster_skills[j].skill_damage_type);
            

            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Skill Subtype: %d", (int *)&game_database->monsters_data.monsters[i].monster_skills[j].skill_modifier);
            

            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Penetration: %f %f %f", &game_database->monsters_data.monsters[i].monster_skills[j].skill_penetration.p1,
            &game_database->monsters_data.monsters[i].monster_skills[j].skill_penetration.p2,
            &game_database->monsters_data.monsters[i].monster_skills[j].skill_penetration.p3);
            
            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Strikes: %ld", &game_database->monsters_data.monsters[i].monster_skills[j].strikes);
            

            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Turns: %ld", &game_database->monsters_data.monsters[i].monster_skills[j].turns);
            

            if (!fgets(buff, PADDING_128, fptr))
                DIE(1, "error reading monster data");
            sscanf(buff, "Description: %[^\n]", game_database->monsters_data.monsters[i].monster_skills[j].description);
        }
    }
}

/*
    Prints all the monsters in the database
*/
void print_all_monsters(monster_database data)
{
    for (size_t i = 0; i < data.number; ++i) {
        printf("Monster Name: %s\n", data.monsters[i].monster_progress.name);
        printf("Monster Level: %ld\n", data.monsters[i].monster_progress.level);
        printf("Monster Exp: %lld\n", data.monsters[i].monster_progress.exp);
        printf("Monster Health: %ld\n", data.monsters[i].monster_stats.health);
        printf("Monster Attack: %ld\n", data.monsters[i].monster_stats.attack);
        printf("Monster Magic: %ld\n", data.monsters[i].monster_stats.magic);
        printf("Monster Defense: %ld\n", data.monsters[i].monster_stats.defense);
        printf("Monster Resistance: %ld\n", data.monsters[i].monster_stats.resistance);
        printf("Monster Dodge: %ld\n", data.monsters[i].monster_stats.dodge);
        printf("Monster Type: %d\n", data.monsters[i].monster_difficulty);
        printf("Monster Faction: %d\n", data.monsters[i].monster_faction);
        printf("Monster Skills: %ld\n", data.monsters[i].skill_number);
        for (size_t j = 0; j < data.monsters[i].skill_number; ++j) {
            printf("Skill Name: %s\n", data.monsters[i].monster_skills[j].skill_progress.name);
            printf("Skill Level: %ld\n", data.monsters[i].monster_skills[j].skill_progress.level);
            printf("Skill Exp: %lld\n", data.monsters[i].monster_skills[j].skill_progress.exp);
            printf("Skill Type: %d\n", data.monsters[i].monster_skills[j].skill_damage_type);
            printf("Skill Subtype: %d\n", data.monsters[i].monster_skills[j].skill_modifier);
            printf("Penetration: %f %f %f\n", data.monsters[i].monster_skills[j].skill_penetration.p1, data.monsters[i].monster_skills[j].skill_penetration.p2, data.monsters[i].monster_skills[j].skill_penetration.p3);
            printf("Strikes: %ld\n", data.monsters[i].monster_skills[j].strikes);
            printf("Turns: %ld\n", data.monsters[i].monster_skills[j].turns);
            printf("Description: %s\n", data.monsters[i].monster_skills[j].description);
        }
    }
}

// MONSTER UTILITIES
