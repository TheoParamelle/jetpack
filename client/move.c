/*
** EPITECH PROJECT, 2022
** jetpack2tek3
** File description:
** main function
*/

#include "includes/my.h"

void move_background(game_t *game)
{
    game->background->x -= 10;
    if (game->background->x <= -1920)
        game->background->x = 1920;
    game->background2->x -= 10;
    if (game->background2->x <= -1920)
        game->background2->x = 1920;
}

void move_character(game_t *game)
{
    sfIntRect *rect = &game->character->rect;
    rect->left += 695;

    if (rect->left >= 3300)
        rect->left = 0;
    sfSprite_setTextureRect(game->character->sprite, *rect);
    game->character->y -= 15 * game->gravity;
}

void move_characterdie(game_t *game)
{
    sfIntRect *rect = &game->characterdie->rect;
    rect->left += 660;

    if (rect->left >= 3100)
        rect->left = 0;
    sfSprite_setTextureRect(game->characterdie->sprite, *rect);
    game->character->y += 25;
}

void move_characterrun(game_t *game)
{
    sfIntRect *rect = &game->characterrun->rect;
    rect->left += 400;
    if (rect->left >= 3100)
        rect->left = 0;
    sfSprite_setTextureRect(game->characterrun->sprite, *rect);
}

void move_obstacle(game_t *game)
{
    game->obstacle->x -= 10;
    if (game->obstacle->x <= -100)
        game->obstacle->x = 2100;
}

void move_coin(game_t *game)
{
    game->coin->x -= 10;
}