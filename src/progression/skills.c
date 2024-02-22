#include "load.h"

/*
    Generates the first skill of the T1 class
*/
skill_info *first_class_skill(char *class)
{
    skill_info *first_skill = malloc(sizeof(skill_info));
    if (!first_skill)
        DIE(1, "error allocating memory for first skill");

    if (strcmp(class, "Warrior") == 0) {
        strcpy(first_skill->skill_progress.name, "Lunge");
        first_skill->skill_progress.level = 0;
        first_skill->skill_progress.exp = 0;
        first_skill->skill_damage_type = 0;
        first_skill->skill_modifier = 1;
        first_skill->skill_penetration.p1 = first_skill->skill_penetration.p2 = first_skill->skill_penetration.p3 = 1;
        first_skill->strikes = 1;
        first_skill->turns = 1;
        strcpy(first_skill->description, "The lunge of an warrior.");
        return first_skill;
    }
    if (strcmp(class, "Mage") == 0) {
        strcpy(first_skill->skill_progress.name, "Bolt");
        first_skill->skill_progress.level = 0;
        first_skill->skill_progress.exp = 0;
        first_skill->skill_damage_type = 1;
        first_skill->skill_modifier = 3;
        first_skill->skill_penetration.p1 = first_skill->skill_penetration.p2 = first_skill->skill_penetration.p3 = 1;
        first_skill->strikes = 1;
        first_skill->turns = 1;
        strcpy(first_skill->description, "A magic bolt.");
        return first_skill;
    }
    if (strcmp(class, "Thief") == 0) {
        strcpy(first_skill->skill_progress.name, "Guts");
        first_skill->skill_progress.level = 0;
        first_skill->skill_progress.exp = 0;
        first_skill->skill_damage_type = 0;
        first_skill->skill_modifier = 1;
        first_skill->skill_penetration.p1 = 1;
        first_skill->skill_penetration.p2 = 0;
        first_skill->skill_penetration.p3 = 2;
        first_skill->strikes = 1;
        first_skill->turns = 1;
        strcpy(first_skill->description, "Strike with fury dealing random damage, but never 0.");
        return first_skill;
    }
    return NULL;
}

/*
    Prints a skill info to a designated file pointer
    See: "utils.h"
*/
void print_skill_function(FILE *fptr, skill_info *skill_data)
{
    fprintf(fptr, "\n");
    fprintf(fptr, "Skill Name: %s\n", skill_data->skill_progress.name);
    fprintf(fptr, "Skill Level: %ld\n", skill_data->skill_progress.level);
    fprintf(fptr, "Skill Exp: %lld\n", skill_data->skill_progress.exp);
    fprintf(fptr, "Skill Type: %d\n", skill_data->skill_damage_type);
    fprintf(fptr, "Skill Subtype: %d\n", skill_data->skill_modifier);
    fprintf(fptr, "Penetration: %f %f %f\n", skill_data->skill_penetration.p1, skill_data->skill_penetration.p2, skill_data->skill_penetration.p3);
    fprintf(fptr, "Strikes: %ld\n",skill_data->strikes);
    fprintf(fptr, "Turns: %ld\n", skill_data->turns);
    fprintf(fptr, "Description: %s", skill_data->description);
}

void read_skill_data(database *game_database, FILE *fptr)
{
    char buff[PADDING_128];
    if (!fgets(buff, PADDING_128, fptr))
        DIE(1, "error reading skill data");

    size_t number = atoi(buff);

    game_database->skills_data.number = number;
    game_database->skills_data.skills = malloc(number * sizeof(skill_info));

    for (size_t i = 0; i < number; ++i) {
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Skill Name: %[^\n]", game_database->skills_data.skills[i].skill_progress.name);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Skill Level: %ld", &game_database->skills_data.skills[i].skill_progress.level);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Skill Exp: %lld", &game_database->skills_data.skills[i].skill_progress.exp);

       if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Skill Type: %d", (int *)&game_database->skills_data.skills[i].skill_damage_type);

       if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Skill Subtype: %d", (int *)&game_database->skills_data.skills[i].skill_modifier);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Penetration: %f %f %f", &game_database->skills_data.skills[i].skill_penetration.p1,
        &game_database->skills_data.skills[i].skill_penetration.p2,
        &game_database->skills_data.skills[i].skill_penetration.p3);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Strikes: %ld", &game_database->skills_data.skills[i].strikes);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Turns: %ld", &game_database->skills_data.skills[i].turns);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading skill data");
        sscanf(buff, "Description: %[^\n]", game_database->skills_data.skills[i].description);
    }
}

void print_all_skills(skill_database skills)
{
    for (size_t i = 0; i < skills.number; ++i) {
        printf("Skill Name: %s\n", skills.skills[i].skill_progress.name);
        printf("Skill Level: %ld\n", skills.skills[i].skill_progress.level);
        printf("Skill Exp: %lld\n", skills.skills[i].skill_progress.exp);
        printf("Skill Type: %d\n", skills.skills[i].skill_damage_type);
        printf("Skill Subtype: %d\n", skills.skills[i].skill_modifier);
        printf("Penetration: %f %f %f\n", skills.skills[i].skill_penetration.p1, skills.skills[i].skill_penetration.p2, skills.skills[i].skill_penetration.p3);
        printf("Strikes: %ld\n",skills.skills[i].strikes);
        printf("Turns: %ld\n", skills.skills[i].turns);
        printf("Description: %s\n", skills.skills[i].description);
    }
}