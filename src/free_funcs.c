/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** free_funcs
*/

#include "my.h"
#include "struct.h"

void free_double(char **map) {
    for (int i = 0; map[i] != NULL; i++) {
        free(map[i]);
    }
    free(map);
}