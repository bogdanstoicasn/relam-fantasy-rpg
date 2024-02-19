#include "../include/library.h"

//TODO: error handler function(future)
/*
    Our entry point in the game
*/
void game_launcher()
{
    player_info *player_information = malloc(sizeof(player_info));
    load_game(player_information);
    free(player_information);
}

int main()
{
    game_launcher();
    return 0;
}