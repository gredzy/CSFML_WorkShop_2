/*
** EPITECH PROJECT, 2023
** CSFML_WORKSHOP
** File description:
** struct.h
*/

#pragma once

#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/System/Time.h>
#include <SFML/Audio.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

#define PRESS 100
#define RELEASE 101
#define TILE_SIZE 20
#define ANIMATION_FRAMES 3
#define ANIMATION_STEP 50
#define ANIMATION_WIDTH (ANIMATION_STEP * ANIMATION_FRAMES)
#define MAP_WIDTH 60
#define MAP_HEIGHT 31
#define TILE_HEIGHT 40
#define PLAYER_SPRITE_HEIGHT 50

typedef struct {
    sfText *txt;
    sfFont *f;
} text;

typedef struct {
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f vect;
    sfIntRect rect;
} sprites;

typedef struct {
    char player;
    char wall;
    char flag;
    char **map;
    int player_x;
    int player_y;
    int getPlayer; // Index of player sprite in the sprites array

    // Movement
    bool isMoving;
    float moveDeltaX, moveDeltaY;

    // Jumping
    bool isJumping;
    bool isFalling;
    float jumpSpeed;
    float jumpHeight;
    float gravity;
    float groundLevel;
} game;


typedef struct {
    sfRenderWindow *window;
    sfEvent event;
    game *gamestruct;
    sfClock *clock;
    sfTime time;
    float second;
    int key_left;
    int key_right;
    int key_up;
    int key_down;
} wdw;
