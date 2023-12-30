/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** creat_sprites
*/

#include "my.h"
#include "struct.h"

sprites *create_object(const char *path_to_spritesheet,
    sfVector2f pos, sfIntRect rect)
{
    sprites *obj = malloc(sizeof(*obj));
    sfTexture *texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
    sfSprite *sprite = sfSprite_create();
    obj->texture = texture;
    obj->rect = rect;
    obj->sprite = sprite;
    obj->vect = pos;
    sfSprite_setPosition(obj->sprite, obj->vect);
    sfSprite_setTexture(obj->sprite, obj->texture, sfTrue);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return obj;
}