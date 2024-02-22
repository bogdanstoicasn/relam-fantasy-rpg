#include "library.h"

/*
    Creates the player file
*/
void create_player_file(char *progress_file)
{
    printf("Give me your name traveler: ");
    char name[PADDING_32];
    fgets(name, 32, stdin);
    name[strlen(name) - 1] = '\0';
    fflush(stdout);

    char *class = first_class_choosing_function();
    skill_info *first_skill = first_class_skill(class);

    FILE *fptr = fopen(progress_file, "w");

    if (!fptr) {
        perror("file not created");
        exit(EXIT_FAILURE);
    }

    fprintf(fptr, "Player Name: %s\n", name);
    fprintf(fptr, "Player Exp: 0\n");
    fprintf(fptr, "Player Points: 0\n");
    fprintf(fptr, "Player Health: 50\n");
    fprintf(fptr, "Player Attack: 5\n");
    fprintf(fptr, "Player Magic: 5\n");
    fprintf(fptr, "Player Defense: 5\n");
    fprintf(fptr, "Player Resistance: 5\n");
    fprintf(fptr, "Player Dodge: 1\n");
    fprintf(fptr, "Player Class: %s\n", class);
    fprintf(fptr, "Player Skills: 1");

    print_skill_function(fptr, first_skill);

    fclose(fptr);
    free(class);
    free(first_skill);
}

// PLAYER UTILITIES
/*
    Read the player progress from the file
*/
void read_player_progress(player_info *player_information, FILE *fptr)
{
    char buff[PADDING_128];

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Name: %s", player_information->player_progress.name);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Exp: %lld", &player_information->player_progress.exp);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Points: %ld", &player_information->free_points);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Health: %ld", &player_information->player_stats.health);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Attack: %ld", &player_information->player_stats.attack);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Magic: %ld", &player_information->player_stats.magic);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Defense: %ld", &player_information->player_stats.defense);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Resistance: %ld", &player_information->player_stats.resistance);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Dodge: %ld", &player_information->player_stats.dodge);

    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Class: %s", player_information->player_class);

    size_t number;
    if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
    sscanf(buff, "Player Skills: %zu", &number);
    
    player_information->skills_number = number;
    player_information->skill_array = malloc(number * sizeof(skill_info));
    skill_info *skill_array = player_information->skill_array;
    if (!skill_array) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < number; i++) {
        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Skill Name: %[^\n]", skill_array[i].skill_progress.name);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Skill Level: %ld", &skill_array[i].skill_progress.level);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Skill Exp: %lld", &skill_array[i].skill_progress.exp);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Skill Type: %d", (int *)&skill_array[i].skill_damage_type);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Skill Subtype: %d", (int *)&skill_array[i].skill_modifier);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Penetration: %f %f %f", &skill_array[i].skill_penetration.p1,
        &skill_array[i].skill_penetration.p2, &skill_array[i].skill_penetration.p3);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Strikes: %ld", &skill_array[i].strikes);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Turns: %ld", &skill_array[i].turns);

        if (!fgets(buff, PADDING_128, fptr))
            DIE(1, "error reading player");
        sscanf(buff, "Description: %[^\n]", skill_array[i].description);
    }
}

/*
    Prints the player progress
    Usefull for debugging
*/
void print_player_progress(player_info *player_information) {
    fprintf(stdout, "Player Name: %s\n", player_information->player_progress.name);
    fprintf(stdout, "Player Exp: %lld\n", player_information->player_progress.exp);
    fprintf(stdout, "Player Points: %ld\n",player_information->free_points);
    fprintf(stdout, "Player Health: %ld\n", player_information->player_stats.health);
    fprintf(stdout, "Player Attack: %ld\n", player_information->player_stats.attack);
    fprintf(stdout, "Player Magic: %ld\n", player_information->player_stats.magic);
    fprintf(stdout, "Player Defense: %ld\n", player_information->player_stats.defense);
    fprintf(stdout, "Player Resistance: %ld\n", player_information->player_stats.resistance);
    fprintf(stdout, "Player Dodge: %ld\n", player_information->player_stats.dodge);
    fprintf(stdout, "Player Class: %s\n", player_information->player_class);
    fprintf(stdout, "Player Skills: %ld\n", player_information->skills_number);

    for (size_t i = 0; i < player_information->skills_number; i++) {
        print_skill_function(stdout, &player_information->skill_array[i]);
    }
}

// PLAYER UTILITIES
