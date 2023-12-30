/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** settings
*/

#include "my.h"
#include "struct.h"

text **text_settings(void)
{
    int len = 2;
    text **t = malloc(sizeof(*t) * len);
    t[0] = create_text("Settings", (sfVector2f){370, 50}, 70, sfWhite);
    t[len - 1] = NULL;
    return t;
}

sprites **sprites_settings(void)
{
    int len = 2;
    sprites **t = malloc(sizeof(*t) * len);
    t[0] = create_object("./ressources/buttons/Back_Btn.png",
        (sfVector2f){5, 645}, (sfIntRect){0, 0, 70, 70});
    t[len - 1] = NULL;
    return t;
}

int check_click(int rep, wdw *wind_struct)
{
    (void)(wind_struct);
    switch (rep) {
        case 0:
            break;
        default:
            return CONTINUE;
    }
    return LOOP;
}

int settings(wdw *wind_struct)
{
    text **t = text_settings();
    sprites **s = sprites_settings();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_sprite(s, wind_struct, true);
        display_text(t, wind_struct);
        int rep = events(wind_struct, s, 0);
        if (rep != LOOP) {
            return check_click(rep, wind_struct);
        }
    }
    return EXIT;
}