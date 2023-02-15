/*
** EPITECH PROJECT, 2022
** MY_H
** File description:
** desc
*/

#ifndef MY_H_
# define MY_H_

#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Graphics.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <stddef.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <string.h>

typedef struct game_object_s {

    const char *path_to_spritesheet;
    sfTexture* texture;
    sfTexture** animation;
    sfSprite* sprite;
    sfVector2f *pos;

    int x;
    int y;
    int gravity;

    sfIntRect rect;
    sfClock *clock;

} game_object_t;

typedef struct map_s
{
    int	width;
    int	height;
    char **data;
}map_t;

typedef enum game_status_s {

    WAIT_START,
    GAME,
    END,
    LOOSE,
    WIN

} game_status_t;

typedef struct game_s {

    game_status_t status;
    sfRenderWindow *window;
    int running;

    sfClock *clock;
    sfTime time;
    float seconds;
    sfFont* font;

    int should_check;
    int lock_x_right;
    int Coincollected;
    int gravity;
    char *score;
    sfText *text;
    int shesh;
    char* first_flag;
    int second_flag;
    int network_socket;
    int error_connexion;
    pthread_mutex_t mutex;

    game_object_t *character;
    game_object_t *characterrun;
    game_object_t *characterdie;
    game_object_t *obstacle;
    game_object_t *background;
    game_object_t *background2;
    game_object_t *coin;
    game_object_t *coin2;
    game_object_t *coin3;
    game_object_t *coin4;
} game_t;

typedef struct client_s
{
    char *ip;
    int id;
    fd_set fds;
    int port;
    map_t *map;
    fd_set rdfds;
    pthread_t thread;
    char started;
    char received;
    int socket_cli;
    game_object_t *character;
} client_t;

game_t *create_game(void);
void create_window(game_t *game);
void free_game(game_t *game);
void launch_game(game_t *game);
void display_game(game_t *game);
void game_loop(game_t *game);
void events(game_t *game, sfRenderWindow *window, sfEvent event);
void obstacle_contact(game_t *game);

void create_background(game_t *game);
void display_background(game_t *game);
void move_background(game_t *game);
void destroy_background(game_t *game);

void create_background_two(game_t *game);
void display_background_two(game_t *game);
void destroy_background_two(game_t *game);

void create_character(game_t *game);
void display_character(game_t *game);
void move_character(game_t *game);
void destroy_character(game_t *game);
void create_characterdie(game_t *game);
void create_characterrun(game_t *game);
void display_characterdie(game_t *game);
void display_characterrun(game_t *game);
void move_characterrun(game_t *game);
void move_characterdie(game_t *game);
void destroy_characterrun(game_t *game);
void destroy_characterdie(game_t *game);

void create_obstacle(game_t *game);
void display_obstacle(game_t *game);
void move_obstacle(game_t *game);
void destroy_obstacle(game_t *game);

void create_coin(game_t *game);
void display_coin(game_t *game);
void move_coin(game_t *game);
void destroy_coin(game_t *game);
void coin_contact(game_t *game);

game_object_t *create_object(char *path, sfVector2f *pos, sfIntRect rect);
void events(game_t *game, sfRenderWindow *window, sfEvent event);
void fin_contact(game_t *game);
void read_map(client_t *client, int width, int height, char *buffer);
void game_loop_two(game_t *game);
void display_game_two(game_t *game);
void display_elements(game_t *game);

void connection(game_t *game);
void graphique(void *d);
int checkerror(int argc, char **argv, game_t *game);
#endif
