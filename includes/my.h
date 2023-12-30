/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** my
*/

#pragma once

#include <stddef.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdarg.h>
#include <stdio.h>
#include <time.h>
#include <SFML/System/Types.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "struct.h"
#include "stdbool.h"
#include <string.h>
#include <math.h>

#define CONTINUE 48
#define LOOP 49
#define EXIT 50
#define ERROR 89

int button_click(wdw *wind_struct, sprites **ar, int start);
int events(wdw *wind_struct, sprites **ar, int start);
text *create_text_sec(char *string, sfVector2f pos, int size, sfColor color);
sprites *create_object(const char *path_to_spritesheet,
    sfVector2f pos, sfIntRect rect);
wdw init_window(char *map_path);
void display_sprite(sprites **struc, wdw *wind_struct, bool d);
void display_text(text **struc, wdw *wind_struct);
char **my_split(char *argv, char *parse, int t);
char *readfile(char *path);
int startmenu(wdw *wind_struct);
void free_double(char **map);
int settings(wdw *wind_struct);
text **create_game_text();
text *create_text(char *string, sfVector2f pos, int size, sfColor color);
char *my_intchar(long long num);
void get_player_pos(game *game_struct, int *position);
sprites *game_asset(game *gamestruct);
sprites **game_background(void);

int move(wdw *wind_struct, sprites **games);

void player_move(wdw *wind_struct, sprites **ar, int start);
void update_game(wdw *wind_struct, sprites **ar);
int move_player(wdw *wind_struct, sprites **ar);
// void player_jump(wdw *wind_struct, sprites **ar, int start);