/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP2
** File description:
** animation
*/

#include "my.h"
#include "struct.h"

void move_right(wdw *wind_struct, sprites *ar) {
    // fill the function to move the player to the right
}

void move_left(wdw *wind_struct, sprites *ar) {
    // fill the function to move the player to the left
}

bool detect_collision(wdw *wind_struct, sprites *player_sprite) {
    //fill the code to detect collision
}


void update_player_movement(wdw *wind_struct, sprites *player_sprite) {
    game *g = wind_struct->gamestruct;

    if (g->isMoving) {
        float movementStep = TILE_SIZE * 0.5; // speed of the player
        if (g->moveDeltaX != 0) {
            player_sprite->vect.x += (g->moveDeltaX > 0) ? movementStep : -movementStep;
            g->moveDeltaX -= (g->moveDeltaX > 0) ? movementStep : -movementStep;
            if (fabs(g->moveDeltaX) < 1) {
                g->isMoving = false;
                g->moveDeltaX = 0;
            }
        }
    }
    if (g->isJumping) {
        float nextY = player_sprite->vect.y + g->moveDeltaY;
        int nextRow = (int)(nextY / TILE_HEIGHT);
        // Update vertical movement
        player_sprite->vect.y = nextY;
        g->moveDeltaY += g->gravity;
        // Check if the jump has reached its peak
        if (g->moveDeltaY >= 0) {
            g->isJumping = false;
            g->moveDeltaY = 0;
        }
    }
}

void jump(wdw *wind_struct, sprites *ar)
{
    game *g = wind_struct->gamestruct;

    if (!g->isJumping && !g->isFalling) {
        g->isJumping = true;
        g->moveDeltaY = -sqrt(2 * g->gravity * g->jumpHeight);
        // continue the code to make the player jump
    }
}

bool check_Win(wdw *wind_struct)
{
    //simple check win function
    return false;
}

int move(wdw *wind_struct, sprites **games) {
    game *g = wind_struct->gamestruct;
    sprites *player_sprite = games[g->getPlayer];

    if (wind_struct->second > 0.025) {
        if (wind_struct->key_right == PRESS) {
            move_right(wind_struct, player_sprite);
        }
        if (wind_struct->key_left == PRESS) {
            move_left(wind_struct, player_sprite);
        }
        if (wind_struct->key_up == PRESS) {
            jump(wind_struct, player_sprite);
        }
        update_player_movement(wind_struct, player_sprite);
        sfClock_restart(wind_struct->clock);
        if (check_Win(wind_struct) == true) {
            return EXIT;
        }
    }
    return LOOP;
}
