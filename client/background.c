/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** background_creator.c
*/

#include "includes/my.h"

void create_background(game_t *game)
{
    game->should_check = 1;
    game->lock_x_right = 180;
    char *path = "client/Sprites/background.png";
    sfVector2f pos = (sfVector2f) {0, 0};
    sfIntRect rect = (sfIntRect) {0, 0, 1920, 1080};
    game->background = create_object(path, &pos, rect);
}

void display_background(game_t *game)
{
    game_object_t *background = game->background;
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    sfSprite_setScale(background->sprite, (sfVector2f) {1, 1});
    int x = game->background->x;
    int y = game->background->y;
    sfSprite_setPosition(game->background->sprite, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(game->window, background->sprite, NULL);
}

void destroy_background(game_t *game)
{
    game_object_t *background = game->background;
    sfTexture_destroy(background->texture);
    sfSprite_destroy(background->sprite);
}

void create_background_two(game_t *game)
{
    game->should_check = 1;
    game->lock_x_right = 180;
    char *path = "client/Sprites/background.png";
    sfVector2f pos = (sfVector2f) {1920, 0};
    sfIntRect rect = (sfIntRect) {0, 0, 1920, 1080};
    game->background2 = create_object(path, &pos, rect);
}

void display_background_two(game_t *game)
{
    game_object_t *background2 = game->background2;
    sfSprite_setTexture(background2->sprite, background2->texture, sfTrue);
    sfSprite_setScale(background2->sprite, (sfVector2f) {1, 1});
    int x = game->background2->x;
    int y = game->background2->y;
    sfSprite_setPosition(game->background2->sprite, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(game->window, background2->sprite, NULL);
}

void destroy_background_two(game_t *game)
{
    game_object_t *background2 = game->background2;
    sfTexture_destroy(background2->texture);
    sfSprite_destroy(background2->sprite);
}