/*
** EPITECH PROJECT, 2022
** jetpack2tek3
** File description:
** main function
*/

#include "includes/my.h"

void create_coin(game_t *game)
{
    char *path = "client/Sprites/Coin.png";
    sfVector2f pos = (sfVector2f) {800, 200};
    sfIntRect rect = (sfIntRect) {0, 0, 1000, 1000};

    game->coin = create_object(path, &pos, rect);
    sfSprite_setTexture(game->coin->sprite, game->coin->texture, sfTrue);
    sfSprite_setScale(game->coin->sprite, (sfVector2f) {1.5, 1.5});
    game->coin->rect.width = 38;
    game->coin->rect.height = 40;
}

void display_coin(game_t *game)
{
    game_object_t *coin = game->coin;
    double x = game->coin->x;
    double y = game->coin->y;

    sfSprite_setTextureRect(game->coin->sprite, game->coin->rect);
    sfSprite_setPosition(game->coin->sprite, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(game->window, coin->sprite, NULL);
}

void destroy_coin(game_t *game)
{
    game_object_t *coin = game->coin;
    sfTexture_destroy(coin->texture);
    sfSprite_destroy(coin->sprite);
}

void coin_contact(game_t *game)
{
    sfVector2f pos_e = sfSprite_getPosition(game->coin->sprite);
    sfVector2f pos_c = sfSprite_getPosition(game->character->sprite);

    if ((pos_e.x - pos_c.x >= 0 && pos_e.x - pos_c.x <= 80) && (pos_e.y - pos_c.y >= -70 && pos_e.y - pos_c.y <= 70)) {
        pthread_mutex_lock(&game->mutex);
        game->Coincollected += 1;
        pthread_mutex_unlock(&game->mutex);
        //sfSprite_setPosition(game->coin->sprite, (sfVector2f) {100, -100});
        //sfRenderWindow_drawSprite(game->window, game->coin->sprite, NULL);
    }
}