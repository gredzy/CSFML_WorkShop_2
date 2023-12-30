/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** menu
*/

#include "my.h"
#include "struct.h"

sprites **menu_sprites(void)
{
    int len = 2;
    sprites **save = malloc(sizeof(*save) * len);
    save[0] = create_object("./ressources/buttons/background.png",
        (sfVector2f){0, 0}, (sfIntRect){0, 0, 1080, 720});
    save[len - 1] = NULL;
    return save;
}

sprites **menu_button(void)
{
    int len = 4;
    sprites **save = malloc(sizeof(*save) * len);
    save[0] = create_object("./ressources/buttons/Exit_Btn.png",
        (sfVector2f){50, 510}, (sfIntRect){0, 0, 240, 80});
    save[1] = create_object("./ressources/buttons/Play_Btn.png",
        (sfVector2f){50, 250}, (sfIntRect){0, 0, 240, 80});
    save[2] = create_object("./ressources/buttons/Settings_Btn.png",
        (sfVector2f){50, 380}, (sfIntRect){0, 0, 240, 80});
    save[len - 1] = NULL;
    return save;
}

int choose(int rep, wdw *wind_struct) {
    switch (rep) {
    case 0:
        return EXIT;
    case 1:
        return CONTINUE;
    case 2:
        return settings(wind_struct);
    default:
        break;
    }
    return LOOP;
}

int startmenu(wdw *wind_struct)
{
    sprites **sp = menu_sprites();
    sprites **buttons = menu_button();
    while (sfRenderWindow_isOpen(wind_struct->window)) {
        display_sprite(sp, wind_struct, true);
        display_sprite(buttons, wind_struct, false);
        int rep = events(wind_struct, buttons, 0);
        rep = choose(rep, wind_struct);
        if (rep != LOOP)
            return rep;
    }
    return EXIT;
}