#include "../include/library.h"

// (def + res)*lvl*10/(lvl+1) = mana 
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
    FILE *fptr = fopen(progress_file, "w");

    if (!fptr) {
        perror("file not created");
        exit(EXIT_FAILURE);
    }

    fprintf(fptr, "Player Name: %s\n", name);
    fprintf(fptr, "Player Level: 0\n");
    fprintf(fptr, "Player Exp: 0\n");
    fprintf(fptr, "Player Health: 100\n");
    fprintf(fptr, "Player Mana: 50\n");
    fprintf(fptr, "Player Attack: 5\n");
    fprintf(fptr, "Player Magic: 5\n");
    fprintf(fptr, "Player Defense: 5\n");
    fprintf(fptr, "Player Resistance: 5\n");
    fprintf(fptr, "Player Dodge: 1\n");
    fprintf(fptr, "Player Class: None\n");
    fprintf(fptr, "Player Skills: None\n");
    fclose(fptr);
}

/*
    Loads the game 
*/
size_t load_game()
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
        create_player_file(buff);
        return 0;
    }
    
    // progress exists
    return 2;
    
}
