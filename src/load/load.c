#include "load.h"

/*
    Loads the progress in player_info 
*/
size_t load_progress(player_info *player_information)
{
    char buff[PADDING_512];
    if (!getcwd(buff, PADDING_512)) {
        perror("cannot use getcwd\n");
        return 1;
    }

    strcat(buff,"/data/current_progress.txt");
    FILE *fptr = fopen(buff, "r");
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
    return 0;
    
}

/*
    Loads the classes in the database
*/
size_t load_class(database *game_database)
{
    char buff[PADDING_512];
    if (!getcwd(buff, PADDING_512)) {
        perror("cannot use getcwd\n");
        return 1;
    }

    strcat(buff, "/data/init/classes.txt");
    FILE *fptr = fopen(buff, "r");
    if (!fptr) {
        perror("cannot find class data");
        return 1;
    }
    read_class_data(game_database, fptr);
    fclose(fptr);
    return 0;
}

/*
    Loads the monsters in the database
*/
size_t load_monster(database *game_database)
{
    char buff[PADDING_512];
    if (!getcwd(buff, PADDING_512)) {
        perror("cannot use getcwd");
        return 1;
    }
    strcat(buff, "/data/init/monsters.txt");
    FILE *fptr = fopen(buff, "r");
    if (!fptr) {
        perror("cannot find monsters data");
        return 1;
    }

    read_monster_data(game_database, fptr);
    fclose(fptr);
    return 0;
}
/*
    Loads the skills in the database
*/
size_t load_skill(database *game_database)
{
    char buff[PADDING_512];
    if (!getcwd(buff, PADDING_512)) {
        perror("cannot use getcwd");
        return 1;
    }

    strcat(buff, "/data/init/skills.txt");
    FILE *fptr = fopen(buff, "r");
    if (!fptr) {
        perror("cannot find skills data");
        return 1;
    }

    read_skill_data(game_database, fptr);
    fclose(fptr);
    return 0;

}
