/*
** EPITECH PROJECT, 2020
** Epitech
** File description:
** background_creator.c
*/

#include "includes/my.h"

void create_character(game_t *game) {
    char *path = "client/Sprites/Jetpack.png";
    sfVector2f pos = (sfVector2f) {100, 700};
    sfIntRect rect = (sfIntRect) {0, 0, 3700, 600};
    game->character = create_object(path, &pos, rect);
    game->character->animation = malloc(sizeof(sfTexture * ) * 1);
    game->character->animation[0] = sfTexture_createFromFile(path, &rect);
    sfTexture **anim = game->character->animation;
    sfSprite_setTexture(game->character->sprite, anim[0], sfTrue);
    game->character->rect.width = 650;
}

void display_character(game_t *game)
{
    game_object_t *character = game->character;
    double x = game->character->x;
    double y = game->character->y;

    sfSprite_setTextureRect(game->character->sprite, game->character->rect);
    sfSprite_setScale(game->character->sprite, (sfVector2f) {0.4, 0.4});
    sfSprite_setPosition(game->character->sprite, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(game->window, character->sprite, NULL);
    //printf("%d\n, position y joueur", game->character->y);
}

void destroy_character(game_t *game)
{
    game_object_t *character = game->character;
    sfTexture_destroy(character->texture);
    sfSprite_destroy(character->sprite);
}
void destroy_characterrun(game_t *game)
{
    game_object_t *characterrun = game->characterrun;
    sfTexture_destroy(characterrun->texture);
    sfSprite_destroy(characterrun->sprite);
}

void destroy_characterdie(game_t *game)
{
    game_object_t *characterdie = game->characterdie;
    sfTexture_destroy(characterdie->texture);
    sfSprite_destroy(characterdie->sprite);
}

void create_characterdie(game_t *game)
{
    char *path = "client/Sprites/Jetpackdie.png";
    sfVector2f *pos = game->character->pos;
    sfIntRect rect = (sfIntRect) {0, 0, 3200, 600};
    game->characterdie = create_object(path, &pos, rect);
    game->characterdie->animation = malloc(sizeof(sfTexture * ) * 1);
    game->characterdie->animation[0] = sfTexture_createFromFile(path, &rect);
    sfTexture **anim = game->characterdie->animation;
    sfSprite_setTexture(game->characterdie->sprite, anim[0], sfTrue);
    game->characterdie->rect.width = 640;
}

void create_characterrun(game_t *game)
{
    char *path = "client/Sprites/Jetpackhappy.png";
    sfVector2f *pos = game->character->pos;
    sfIntRect rect = (sfIntRect) {0, 0, 3200, 600};
    game->characterrun = create_object(path, &pos, rect);
    game->characterrun->animation = malloc(sizeof(sfTexture * ) * 1);
    game->characterrun->animation[0] = sfTexture_createFromFile(path, &rect);
    sfTexture **anim = game->characterrun->animation;
    sfSprite_setTexture(game->characterrun->sprite, anim[0], sfTrue);
    game->characterrun->rect.width = 640;
}

void display_characterdie(game_t *game) {
    game_object_t *characterdie = game->characterdie;
    double x = game->character->x;
    double y = game->character->y;

    sfSprite_setTextureRect(game->characterdie->sprite, game->characterdie->rect);
    sfSprite_setScale(game->characterdie->sprite, (sfVector2f) {0.4, 0.4});
    sfSprite_setPosition(game->characterdie->sprite, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(game->window, characterdie->sprite, NULL);
    //printf("%d\n, position y joueur", game->character->y);
}

void display_characterrun(game_t *game)
{
    game_object_t *characterrun = game->characterrun;
    double x = game->character->x;
    double y = game->character->y;

    sfSprite_setTextureRect(game->characterrun->sprite, game->characterrun->rect);
    sfSprite_setScale(game->characterrun->sprite, (sfVector2f) {0.4, 0.4});
    sfSprite_setPosition(game->characterrun->sprite, (sfVector2f) {x, y});
    sfRenderWindow_drawSprite(game->window, characterrun->sprite, NULL);
    //printf("%d\n, position y joueur", game->character->y);
}
