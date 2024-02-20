#include "../include/library.h"

//TODO: error handler function(future)
/*
    Our entry point in the game
*/
void game_launcher()
{
    player_info *player_information = malloc(sizeof(player_info));
    size_t err = load_game(player_information);
    print_player_progress(player_information);
    free(player_information->skill_array);
    
    free(player_information);
}

int main()
{
    game_launcher();
    return 0;
}