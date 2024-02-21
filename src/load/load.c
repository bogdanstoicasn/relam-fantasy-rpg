#include "load.h"

/*
    Loads the progress in player_info 
*/
size_t load_progress(player_info *player_information)
{
    char buff[PADDING_512];
    if (!getcwd(buff, PADDING_1024)) {
        perror("cannot fin progress dir\n");
        return 0;
    }

    strcat(buff,"/data/current_progress.txt");
    FILE *fptr = fopen(buff, "r");
    if (!fptr) {
        // create initial character if the progress doesn't exist
        create_player_file(buff);
        FILE *temp = fopen(buff, "r");
        read_player_progress(player_information, temp);
        fclose(temp);
        return 1;
    }
    
    read_player_progress(player_information, fptr);
    fclose(fptr);
    return 2;
    
}

size_t load_class(database *game_database)
{
    char buff[PADDING_512];
    if (!getcwd(buff, PADDING_256)) {
        perror("cannot find class progression\n");
        return 0;
    }
}