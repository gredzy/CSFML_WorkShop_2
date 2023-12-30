/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** game
*/

#include "my.h"
#include "struct.h"

int calculate_sprites_count(char **map) {
    int count = 0;
    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            if (map[i][j] == '#' || map[i][j] == 'P' || map[i][j] == 'F') {
                count++;
            }
        }
    }
    return count;
}

sprites *create_sprite_at(char *filepath, int row, int col, sfIntRect rect) {
    // Convert row and col to pixel coordinates
    sfVector2f pos = {col * 22, row * 22}; // Define TILE_WIDTH and TILE_HEIGHT based on your sprite size
    return create_object(filepath, pos, rect);
}

// Then you can have specific functions like:
sprites *create_wall_sprite_at(int row, int col) {
    return create_sprite_at("./ressources/playerAssets/brick.png", row, col, (sfIntRect){0, 0, 40, 40});
}

sprites *create_player_sprite_at(int row, int col) {
    return create_sprite_at("./ressources/playerAssets/mario.png", row, col, (sfIntRect){150, 0, 50, 50});
}

sprites *create_flag_sprite_at(int row, int col) {
    return create_sprite_at("./ressources/playerAssets/endingFlag.png", row, col, (sfIntRect){0, 0, 100, 100});
}

sprites *game_asset(game *gamestruct) {
    ///function to get all the prite in the map
}

sprites **game_background(void)
{
    int len = 2;
    sprites **save = malloc(sizeof(*save) * len);
    save[0] = create_object("./ressources/playerAssets/background.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 1310, 720});
    save[len - 1] = NULL;
    return save;
}
