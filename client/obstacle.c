/*
** EPITECH PROJECT, 2022
** jetpack2tek3
** File description:
** main function
*/

#include "includes/my.h"

void create_obstacle(game_t *game)
{
    char *path = "client/Sprites/Obstacle.png";
    sfVector2f pos = (sfVector2f) {400, 300};
    sfIntRect rect = (sfIntRect) {0, 0, 1000, 1000};

    game->obstacle = create_object(path, &pos, rect);
    sfSprite_setTexture(game->obstacle->sprite, game->obstacle->texture, sfTrue);
    sfSprite_setScale(game->obstacle->sprite, (sfVector2f) {1, 1});
    game->obstacle->rect.width = 90;
    game->obstacle->rect.height = 250;
}

void display_obstacle(game_t *game)
{
    game_object_t *obstacle = game->obstacle;
    double x = game->obstacle->x;
    double y = game->obstacle->y;

    sfSprite_setTextureRect(game->obstacle->sprite, game->obstacle->rect);
    sfSprite_setPosition(game->obstacle->sprite, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(game->window, obstacle->sprite, NULL);
}

void destroy_obstacle(game_t *game)
{
    game_object_t *obstacle = game->obstacle;
    sfTexture_destroy(obstacle->texture);
    sfSprite_destroy(obstacle->sprite);
}