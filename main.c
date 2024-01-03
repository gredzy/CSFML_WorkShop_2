/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** main
*/

#include "my.h"
#include "struct.h"

void startgame(wdw *wind_struct)
{
    text **t = create_game_text();
    sprites **background = game_background();
    sprites **sp = background; // game_asset(wind_struct->gamestruct);
    (void)(t);
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        sfRenderWindow_display(wind_struct->window);
        display_sprite(background, wind_struct, true);
        // display_sprite(sp, wind_struct, false);
        wind_struct->time = sfClock_getElapsedTime(wind_struct->clock);
        wind_struct->second = wind_struct->time.microseconds / 1000000.0;
        int rep = events(wind_struct, sp, 0);
        int isWin = move(wind_struct, sp);
        if (rep != LOOP)
            exit(0);
        if (isWin == 1)
            exit(0);
    }
}

void start(wdw *wind_struct)
{
    int rep = startmenu(wind_struct);
    if (rep == EXIT)
        exit(0);
    startgame(wind_struct);
    free_double(wind_struct->gamestruct->map);
}

int main(int argv, char **argc)
{
    if (argv != 2) {
        printf("Error add a path for the Map\n");
        exit(84);
    }
    wdw wind_struct = init_window(argc[1]);
    start(&wind_struct);
    return 0;
}