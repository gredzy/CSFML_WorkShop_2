/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** creat_text
*/

#include "my.h"
#include "struct.h"

text *create_text(char *string, sfVector2f pos, int size, sfColor color)
{
    text *obj = malloc(sizeof(*obj));
    sfFont *font = sfFont_createFromFile("./ressources/ttf/arial.ttf");
    sfText *tst = sfText_create();
    sfText_setString(tst, string);
    sfText_setFont(tst, font);
    sfText_setCharacterSize(tst, size);
    sfText_setColor(tst, color);
    sfText_setPosition(tst, pos);
    obj->f = font;
    obj->txt = tst;
    return obj;
}

text **create_game_text(void)
{
    int len = 2;
    text **t = malloc(sizeof(*t) * len);
    t[0] = create_text("The Game", (sfVector2f){370, 50}, 70, sfWhite);
    t[len - 1] = NULL;
    return t;
}
