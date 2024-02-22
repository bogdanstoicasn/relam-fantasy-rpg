#include "load.h"

//TODO: error handler function(future)
// 0-> on success
// 1-> data failure
size_t error_number;
/*
    Our entry point in the game
*/
void free_game_data(player_info *player, database *game)
{
    for (size_t i = 0; i < game->monsters_data.number; ++i)
        free(game->monsters_data.monsters[i].monster_skills);
    free(game->monsters_data.monsters);

    free(game->skills_data.skills);

    free(game->classes_data.classes);

    free(game);

    free(player->skill_array);
    free(player);
}

void game_launcher()
{
    player_info *player_information = malloc(sizeof(player_info));
    if (!player_information)
        DIE(1,"Memory allocation failed for player_information");

    database *game_database = malloc(sizeof(database));
    if (!game_database)
        DIE(1,"Memory allocation failed for game_database");

    graphics *game_graphics = malloc(sizeof(graphics));

    error_number = load_progress(player_information);
    print_player_progress(player_information);

    error_number = load_class(game_database);
    print_all_classes(game_database->classes_data);

    error_number = load_monster(game_database);
    print_all_monsters(game_database->monsters_data);

    error_number = load_skill(game_database);
    print_all_skills(game_database->skills_data);

    free_game_data(player_information, game_database);

    free(game_graphics);
}

int main()
{
    game_launcher();
    return 0;
}