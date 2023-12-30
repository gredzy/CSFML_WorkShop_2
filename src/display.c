/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** display
*/

#include "my.h"
#include "struct.h"

void display_sprite(sprites **struc, wdw *wind_struct, bool d)
{
    if (d) {
        sfRenderWindow_display(wind_struct->window);
        sfRenderWindow_clear(wind_struct->window, sfBlack);
    }
    for (int c = 0; struc[c] != NULL; c++) {
        sfSprite_setTextureRect(struc[c]->sprite, struc[c]->rect);
        sfSprite_setPosition(struc[c]->sprite, struc[c]->vect);
        sfRenderWindow_drawSprite(wind_struct->window, struc[c]->sprite, NULL);
    }
}

void display_text(text **struc, wdw *wind_struct)
{
    for (int c = 0; struc[c] != NULL; c++) {
        sfRenderWindow_drawText(wind_struct->window, struc[c]->txt, NULL);
    }
}