/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle
** File description:
** server
*/

#include "server.h"

int check_args(int argc, char **argv, server_t *server)
{
    if (argc != 7) {
        printf("Usage: ./serverJ2T3 -p <port> -g <gravity> -m <map>\n");
        exit(84);
    }
    if (strcmp(argv[1], "-p") == 0)
        server->port = atoi(argv[2]);
    else
        exit(84);
    if (strcmp(argv[3], "-g") == 0) {
        server->gravity =  atoi(argv[4]);
        if (server->gravity < 0)
             exit(84);
    }
    if (strcmp(argv[5], "-m") == 0);
            if (check_maps(argv[6], server) == 84)
                exit(84);
}

void launch_server(server_t *server)
{
    int client_fd;
    struct sockaddr_in client_addr;
    size_t client_addr_s = sizeof(client_addr);

    FD_ZERO(&server->readfds);
    FD_SET(server->socket_server, &server->writefds);
    while(1) {
        server->readfds = server->writefds;
        select(server->fd_actual + 1, &server->readfds, NULL, NULL, NULL);
        client_checking_handler(server);
    }
    shutdown(server->socket_server, 2);
    close(server->socket_server);
}

int server_init(int argc, char** argv)
{
    server_t *server = malloc(sizeof(server_t));

    check_args(argc, argv, server);
    init_struct_server(server);
    launch_server(server);
    free(server);

    return (0);
}