/*
** EPITECH PROJECT, 2022
** jetpack2totek3
** File description:
** check end
*/

#include "includes/my.h"

void game_loop(game_t *game)
{
    game->text = sfText_create();
    game->gravity = 1;
    game->font = sfFont_createFromFile("client/Sprites/font.ttf");
    game->score = malloc(sizeof(char)* 100);
    sprintf(game->score, "Score: %d       Coin: %d", game->shesh, game->Coincollected);
    sfText_setString(game->text, game->score);
    sfText_setFont(game->text, game->font);
    sfText_setCharacterSize(game->text, 50);
    sfText_setColor(game->text, sfBlack);

    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue && game->status == GAME) {
        if (game->character->y > 150)
            move_character(game);
    }
    else if (game->character->y > 100 && game->character->y < 730) {
            game->character->y += 15 * game->gravity;
    }
    if (game->status == GAME) {
        move_background(game);
        move_obstacle(game);
        move_coin(game);
        obstacle_contact(game);
        coin_contact(game);
        game->shesh = game->shesh + 1;
        //check_coin(game);
    }
    game_loop_two(game);
}

void game_loop_two(game_t *game)
{
    sfRenderWindow_drawText(game->window, game->text, NULL);

    if (game->status == LOOSE) {
        sprintf(game->score, "LOOSE");
        sfText_setString(game->text, game->score);
        sfText_setFont(game->text, game->font);
        sfText_setCharacterSize(game->text, 200);
        sfText_setColor(game->text, sfBlack);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
    if (game->status == WIN) {
        sprintf(game->score, "WIN");
        sfText_setString(game->text, game->score);
        sfText_setFont(game->text, game->font);
        sfText_setCharacterSize(game->text, 200);
        sfText_setColor(game->text, sfBlack);
        sfRenderWindow_drawText(game->window, game->text, NULL);
    }
    if (game->shesh >= 250 /*&& receive piece collecte par joeur adverse si supérieur alors win || player2 game status are LOOSE*/)
        game->status = WIN;
    if (game->character->y > 100 && game->character->y < 730 && game->status == LOOSE)
        move_characterdie(game);
}

void events(game_t *game, sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
        }
    }
}

void obstacle_contact(game_t *game)
{
    sfVector2f pos_e = sfSprite_getPosition(game->obstacle->sprite);
    sfVector2f pos_c = sfSprite_getPosition(game->character->sprite);

    if ((pos_e.x - pos_c.x >= 0 && pos_e.x - pos_c.x <= 80) && (pos_e.y - pos_c.y >= -160 && pos_e.y - pos_c.y <= 160)) {
        //if (player 2 a deja perdu)
            //game->status = WIN;
        game->status = LOOSE;
    }
}

game_object_t *create_object(char *path, sfVector2f *pos, sfIntRect rect)
{
    game_object_t *object = malloc(sizeof(game_object_t));
    object->path_to_spritesheet = path;
    object->sprite = sfSprite_create();
    object->texture = sfTexture_createFromFile(path, &rect);
    object->rect = rect;
    object->x = pos->x;
    object->y = pos->y;
    return (object);
}

void read_map(client_t *client, int width, int height, char *buffer)
{
    if (client->map)
        return;
    client->map = malloc(sizeof(map_t));
    client->map->width = width;
    client->map->height = height;
    //get_map_data(buffer, client->map);
}

/*1080/8;
taille de tuile;
108x108;
char**map;
si map[I][J] = 'c';
sfvector a envoye vers create_coin avec struct pour set la position selon la lecture de map;
draw chaque objet;
*/
