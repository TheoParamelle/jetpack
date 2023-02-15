/*
** EPITECH PROJECT, 2022
** jetpack2tek3
** File description:
** main function
*/

#include "includes/my.h"

void create_window(game_t *game)
{
    sfVideoMode mode = {1920, 1080, 60};
    char *name = "Jetpack2tek3";
    game->window = sfRenderWindow_create(mode, name, sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 30);
}

game_t *create_game(void)
{
    game_t *game = malloc(sizeof(game_t));
    create_window(game);
    game->status = GAME;
    game->clock = sfClock_create();
    create_background(game);
    create_background_two(game);
    create_character(game);
    create_characterrun(game);
    create_characterdie(game);
    create_coin(game);
    //create_map(game);
    create_obstacle(game);
    return game;
}

void free_game(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    sfClock_destroy(game->clock);
    destroy_background(game);
    destroy_background_two(game);
    destroy_character(game);
    destroy_characterrun(game);
    destroy_characterdie(game);
    //destroy_map(game);
    free(game);
}

void display_game(game_t *game)
{
    if (game->status == WAIT_START) {
        display_elements(game);
        int i;
        i = send(game->network_socket, "ATTENTE Demarrage\n", 18, 0);
        if (i < 0)
            printf("error\n");
    }
    if (game->status == GAME) {
        display_elements(game);
    }
    display_game_two(game);
}

void display_game_two(game_t *game)
{
    if (game->status == END) {
        display_elements(game);
        //wait(100);
        //printf("fini la map, attente réponse serveur pour savoir si win ou loose");
    }
    if (game->status == LOOSE) {
        display_background(game);
        display_background_two(game);
        display_characterdie(game);
        display_obstacle(game);
        //send perdu au serveur;
    }
    if (game->status == WIN) {
        display_background(game);
        display_background_two(game);
        display_characterrun(game);
        display_obstacle(game);
    }
}

void display_elements(game_t *game)
{
    display_background(game);
    display_background_two(game);
    display_character(game);
    display_obstacle(game);
    display_coin(game);
}