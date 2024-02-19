#include "../include/library.h"

// (def + res)*lvl*10/(lvl+1) = mana 
// ok

/*
    Creates the player file
*/
void create_player_file(char *progress_file, player_info *player_information)
{
    printf("Give me your name traveler: ");
    char name[PADDING_32];
    fgets(name, 32, stdin);
    name[strlen(name) - 1] = '\0';

    fflush(stdout);
    char *class = first_class_choosing_function();
    skill_info *first_skill = first_class_skill(class, player_information);
    FILE *fptr = fopen(progress_file, "w");

    if (!fptr) {
        perror("file not created");
        exit(EXIT_FAILURE);
    }

    fprintf(fptr, "Player Name: %s\n", name);
    fprintf(fptr, "Player Exp: 0\n");
    fprintf(fptr, "Player Health: 100\n");
    fprintf(fptr, "Player Mana: 50\n");
    fprintf(fptr, "Player Attack: 5\n");
    fprintf(fptr, "Player Magic: 5\n");
    fprintf(fptr, "Player Defense: 5\n");
    fprintf(fptr, "Player Resistance: 5\n");
    fprintf(fptr, "Player Dodge: 1\n");
    fprintf(fptr, "Player Class: %s\n", class);
    fprintf(fptr, "Player Skills: None\n");

    fclose(fptr);
    free(class);
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

    if (!fptr) {
        // create initial character if the progress doesn't exist
        create_player_file(buff, player_information);
        return 0;
    }
    
    // progress exists
    return 2;
    
}
