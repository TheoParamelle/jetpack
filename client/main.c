/*
** EPITECH PROJECT, 2022
** jetpack2tek3
** File description:
** main function
*/

#include "includes/my.h"

int main (int argc, char **argv)
{
    game_t *game = create_game();
    int i = checkerror(argc, argv, game);
    if (i == 84)
        return 84;
    pthread_t thread;
    int connection_thread = pthread_create(&thread, NULL, &connection, game);
    pthread_join(thread, NULL);
    game->shesh = 0;
    game->Coincollected = 0;
    sfEvent event;

    while (sfRenderWindow_isOpen(game->window)) {
        events(game, game->window, event);
        sfRenderWindow_clear(game->window, sfWhite);
        display_game(game);
        game_loop(game);
        sfRenderWindow_display(game->window);
    }
    free_game(game);
    return 0;
}

int checkerror(int argc, char **argv, game_t *game)
{
    if (argc < 5)
        return 84;
    if (argv[1][0] != '-' && argv[1][1] != 'h')
        return 84;
    if (argv[3][0] != '-' && argv[3][1] != 'p')
        return 84;
    game->first_flag = (argv[2]);
    game->second_flag = atoi(argv[4]);
    return 0;
}

void connection(game_t *game)
{
    game->network_socket = socket(AF_INET, SOCK_STREAM,0);
    //specify an address for the socket
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(game->second_flag);
    server_address.sin_addr.s_addr = inet_addr(game->first_flag);
    int connect_status = connect(game->network_socket, (struct sockaddr *) &server_address,sizeof(server_address));
    if (connect_status == -1) {
        free_game(game);
        exit(84);
    }
}
