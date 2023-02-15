/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle
** File description:
** client
*/

#include "server.h"

void client_init(server_t *server)
{
        server->client[0].logged = false;
        server->client[0].score = 0;
        server->client[0].uid = 0;
        server->client[0].ip = 0;
        server->client[0].client_socket = 0;
        server->client[1].logged = false;
        server->client[1].score = 0;
        server->client[1].uid = 0;
        server->client[1].ip = 0;
        server->client[1].client_socket = 0;
}

void client_connection(server_t *server, int i)
{
    struct sockaddr_in client_addr;
    size_t client_addr_size = sizeof(client_addr);
    int client = 0;
    int client_fd = 0;

    if (server->socket_server == i) {
        client = accept(i, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client == -1)
            exit(84);
        FD_SET(client, &server->writefds);
        server->fd_actual++;
    } else
        client_read_write(server, i);
}

char *read_client_message(int sock)
{
    char buffer[1024];
    int i = 0;
    char *message = NULL;

    read(sock, buffer, sizeof(buffer));
    for (;buffer[i++] != '\n';);
    buffer[i - 1] = '\0';
    return strdup(buffer);
}

void parse_client_message(server_t *server, char *buffer, int i)
{
    if (strcmp(buffer, "MAP\n") == 0)
        dprintf(i ,"MAP %d %d %s\n",server->map->width, server->map->height, server->map->map);
    if (strcmp(buffer, "ID\n") == 0)
        dprintf(i ,"ID %d\n", i);
    if (strcmp(buffer, "READY\n") == 0)
        server->ready++;
}

void client_read_write(server_t *server, int i)
{
    char buff[1024];

    bzero(buff, sizeof(buff));
    recv(i, buff, sizeof(buff), 0);
    parse_client_message(server, buff, i);
}

void client_checking_handler(server_t *server)
{
    for (int i = 0; i < server->fd_actual + 1; i++) {
        if (FD_ISSET(i, &server->readfds))
            client_connection(server, i);
    }
}
