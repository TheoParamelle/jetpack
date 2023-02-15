/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle
** File description:
** server_init
*/

#include "my.h"
#include "server.h"


void init_struct_server(server_t *server)
{
    server->players = malloc(sizeof(player_t) * 2);
    server->client = malloc(sizeof(client_t) * 2);
    start_init(server);
}

void start_init(server_t *server)
{
    server->players[0].gravity = server->gravity;
    server->players[1].gravity = server->gravity;
    server->protocol = getprotobyname("TCP");
    // server->status_server = 1;
    server->socket_server = socket(AF_INET, SOCK_STREAM, 0);
    server->fd_actual = server->socket_server;
    server->sin_size = sizeof(server->sin);
    server->sin.sin_port = htons(server->port);
    server->sin.sin_addr.s_addr = htonl(INADDR_ANY);
    server->sin.sin_family = AF_INET;

    check_server_error(server);
    client_init(server);
    bind_server(server);
}

void check_server_error(server_t *server)
{
    if(server->protocol == NULL)
        exit(84);
    if(server->socket_server == -1)
        exit(84);
}

void bind_server(server_t *server)
{
    if (bind(server->socket_server, (struct soaddr_t *)&server->sin, sizeof(server->sin)) == -1) {
        shutdown(server->socket_server, SHUT_RDWR);
        close(server->socket_server);
        exit(84);
    }

    if (listen(server->socket_server, 2)) {
        shutdown(server->socket_server, SHUT_RDWR);
        close(server->socket_server);
        exit(84);
    }
}



