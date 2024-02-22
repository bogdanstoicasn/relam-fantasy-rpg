#ifndef LOAD_H
#define LOAD_H

#include "library.h"


size_t load_progress(player_info *player_information);
size_t load_class(database *game_database);
size_t load_monster(database *game_database);
size_t load_skill(database *game_database);

#endif