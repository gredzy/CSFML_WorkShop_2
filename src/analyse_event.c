/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** analyse_event
*/

#include "my.h"
#include "struct.h"

int button_click(wdw *wind_struct, sprites **ar, int start) {
    if (ar == NULL) {
        return LOOP;
    }
    int k = wind_struct->event.mouseButton.button;
    int x = wind_struct->event.mouseButton.x;
    int y = wind_struct->event.mouseButton.y;
    for (int c = start; ar[c] != NULL; c++) {
        if (x >= ar[c]->vect.x &&
            x <= ar[c]->vect.x + ar[c]->rect.width &&
            y >= ar[c]->vect.y &&
            y <= ar[c]->vect.y + ar[c]->rect.height) {
            c = k == 1 ? c * -1 : c;
            return c;
        }
    }
    return LOOP;
}

//for your information
// 71 = KEY LEFT
// 72 = KEY RIGHT
// 73 = KEY UP
// 74 = KEY DOWN

init_move_player(wdw *wind_struct, sprites **ar)
{
    // PRESS keyboard to init movement
}

stop_move_player(wdw *wind_struct, sprites **ar)
{
    // RELEASE keyboard to stop movement
}



int events(wdw *wind_struct, sprites **ar, int start)
{
    while (sfRenderWindow_pollEvent
        (wind_struct->window, &wind_struct->event)) {
            if (wind_struct->event.type == sfEvtKeyPressed) {
                init_move_player(wind_struct, ar);
            }
            if (wind_struct->event.type == sfEvtKeyReleased) {
                stop_move_player(wind_struct, ar);
            }
            switch (wind_struct->event.type) {
                case sfEvtClosed:
                    sfRenderWindow_close(wind_struct->window);
                    break;
                case sfEvtMouseButtonPressed:
                    return button_click(wind_struct, ar, start);
                case sfEvtKeyPressed:
                    return wind_struct->event.key.code;
                default:
                    continue;
            }
    }
    return LOOP;
}