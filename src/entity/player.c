#include "../include/library.h"

// (def + res)*lvl*10/(lvl+1) = life
// ok

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
    fprintf(fptr, "Player Health: 100\n");
    fprintf(fptr, "Player Attack: 5\n");
    fprintf(fptr, "Player Magic: 5\n");
    fprintf(fptr, "Player Defense: 5\n");
    fprintf(fptr, "Player Resistance: 5\n");
    fprintf(fptr, "Player Dodge: 1\n");
    fprintf(fptr, "Player Class: %s\n", class);
    fprintf(fptr, "Player Skills: 1");

    skill_print_function(fptr, first_skill);

    fclose(fptr);
    free(class);
    free(first_skill);
}

void read_player_progress(player_info *player_information, FILE *fptr) {
    char buff[PADDING_128];

    // read player info from progress
    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Name: %s", player_information->player_progress.name);

    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Exp: %lld", &player_information->player_progress.exp);

    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Health: %ld", &player_information->health);

    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Attack: %ld", &player_information->player_stats.attack);

    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Magic: %ld", &player_information->player_stats.magic);

    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Defense: %ld", &player_information->player_stats.defense);

    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Resistance: %ld", &player_information->player_stats.resistance);

    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Dodge: %ld", &player_information->player_stats.dodge);

    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Class: %s", player_information->player_class);

    size_t number;
    fgets(buff, PADDING_128, fptr);
    sscanf(buff, "Player Skills: %zu", &number);
    
    player_information->skills_number = number;

    skill_info *skill_array = malloc(number * sizeof(skill_info));
    if (skill_array == NULL) {
        // Handle memory allocation failure
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < number; i++) {
        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Skill Name: %s", skill_array[i].skill_progress.name);

        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Skill Level: %ld", &skill_array[i].skill_progress.level);

        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Skill Exp: %lld", &skill_array[i].skill_progress.exp);

        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Skill Type: %d", (int *)&skill_array[i].skill_damage_type);

        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Skill Subtype: %d", (int *)&skill_array[i].skill_modifier);

        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Penetration: %f %f %f", &skill_array[i].skill_penetration.p1, &skill_array[i].skill_penetration.p2, &skill_array[i].skill_penetration.p3);

        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Strikes: %ld", &skill_array[i].strikes);

        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Turns: %ld", &skill_array[i].turns);

        fgets(buff, PADDING_128, fptr);
        sscanf(buff, "Description: %[^\n]", skill_array[i].description);
    }

    player_information->skill_array = skill_array;
}


void print_player_progress(player_info *player_information) {
    fprintf(stdout, "Player Name: %s\n", player_information->player_progress.name);
    fprintf(stdout, "Player Exp: %lld\n", player_information->player_progress.exp);
    fprintf(stdout, "Player Health: %ld\n", player_information->health);
    fprintf(stdout, "Player Attack: %ld\n", player_information->player_stats.attack);
    fprintf(stdout, "Player Magic: %ld\n", player_information->player_stats.magic);
    fprintf(stdout, "Player Defense: %ld\n", player_information->player_stats.defense);
    fprintf(stdout, "Player Resistance: %ld\n", player_information->player_stats.resistance);
    fprintf(stdout, "Player Dodge: %ld\n", player_information->player_stats.dodge);
    fprintf(stdout, "Player Class: %s\n", player_information->player_class);
    fprintf(stdout, "Player Skills: %ld\n", player_information->skills_number);

    for (size_t i = 0; i < player_information->skills_number; i++) {
        skill_print_function(stdout, &player_information->skill_array[i]);
    }
}


/*
    Loads the game 
*/
size_t load_game(player_info *player_information)
{
    char buff[PADDING_1024];
    if (!getcwd(buff, PADDING_1024)) {
        perror("cannot fin progress dir");
        return 0;
    }

    strcat(buff,"/data/current_progress.txt");
    FILE *fptr = fopen(buff, "r");
    (void)player_information;
    if (!fptr) {
        // create initial character if the progress doesn't exist
        create_player_file(buff);
        FILE *temp = fopen(buff, "r");
        read_player_progress(player_information, temp);
        fclose(temp);
        return 0;
    }
    
    read_player_progress(player_information, fptr);
    fclose(fptr);
    // progress exists, TODO: read player info here
    return 2;
    
}
