#include "../include/library.h"

skill_info *first_class_skill(char *class)
{
    skill_info *first_skill = malloc(sizeof(skill_info));
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

void skill_print_function(FILE *fptr, skill_info *skill_data)
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