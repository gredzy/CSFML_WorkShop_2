/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** init_struct.c
*/
#include "my.h"
#include "struct.h"

game *init_game(char *map_path) {
    game *gamestruct = malloc(sizeof(game));
    if (!gamestruct) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }

    char *map = readfile(map_path);
    gamestruct->map = my_split(map, "\n", 0);
    gamestruct->player = 'P';
    gamestruct->wall = '#';
    gamestruct->flag = 'F';
    gamestruct->getPlayer = 0; // Index of the player sprite
    gamestruct->isMoving = false;
    gamestruct->moveDeltaX = 0.0f;
    gamestruct->isJumping = false;
    gamestruct->isFalling = false;
    gamestruct->jumpSpeed = 1.0f;
    gamestruct->jumpHeight = 39.1f; // Set in the game loop when player is first drawn
    gamestruct->gravity = 1.0f; // Set in the game loop when player is first drawn
    gamestruct->groundLevel = 500.0f; // Set in the game loop when player is first drawn

    int playerPosition[2];
    get_player_pos(gamestruct, playerPosition);
    if (playerPosition[0] == -1) {
        printf("BAD MAP\n");
        exit(EXIT_FAILURE);
    }
    gamestruct->player_y = playerPosition[0];
    gamestruct->player_x = playerPosition[1];

    free(map);
    return gamestruct;
}


wdw init_window(char *map_path) {
    wdw wind_struct;
    sfVideoMode video_mode = {1310, 720, 32};
    wind_struct.window = sfRenderWindow_create(video_mode, "Game", sfClose | sfResize, NULL);
    if (!wind_struct.window) {
        perror("Window creation failed");
        exit(0);
    }

    sfRenderWindow_setFramerateLimit(wind_struct.window, 60);
    wind_struct.clock = sfClock_create();
    wind_struct.second = 0;
    wind_struct.key_left = RELEASE;
    wind_struct.key_right = RELEASE;
    wind_struct.key_up = RELEASE;
    wind_struct.gamestruct = init_game(map_path);

    return wind_struct;
}
