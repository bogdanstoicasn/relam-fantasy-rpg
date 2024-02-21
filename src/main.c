#include "load.h"

//TODO: error handler function(future)
/*
    Our entry point in the game
*/
void game_launcher()
{
    player_info *player_information = malloc(sizeof(player_info));
    database *game_database = malloc(sizeof(database));
    size_t error_number = load_progress(player_information);
    print_player_progress(player_information);

    free(game_database);
    free(player_information->skill_array);    
    free(player_information);
}

int main()
{
    game_launcher();
    return 0;
}