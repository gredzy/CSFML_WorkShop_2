/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** read_map
*/

#include "my.h"
#include "struct.h"

char *readfile(char *path)
{
    int rt;
    int file;
    struct stat size_buf;
    stat(path, &size_buf);
    file = open(path, O_RDONLY);
    if (file == -1) {
        printf("Error: Can't open file\n");
        exit(84);
    }
    char *buffer = malloc(size_buf.st_size + 3);
    rt = read(file, buffer, size_buf.st_size);
    if (rt == -1) {
        free(buffer);
        return "error";
    }
    buffer[rt] = '\0';
    return buffer;
}

void get_player_pos(game *game_struct, int *position)
{
    for (int i = 0; game_struct->map[i] != NULL; i++) {
        for (int c = 0; game_struct->map[i][c] != '\0'; c++) {
            if (game_struct->map[i][c] == game_struct->player) {
                position[0] = i;
                position[1] = c;
                return;
            }
        }
    }
    position[0] = -1;
    position[1] = -1;
}

