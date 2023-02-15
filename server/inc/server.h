/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle
** File description:
** server
*/

#ifndef SERVER_H_
#define SERVER_H_

#include <stdio.h>
#include <ctype.h>
#include <errno.h>
#include <signal.h>
#include <uuid/uuid.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "player.h"

typedef struct map_s {
  int   width;
  int   height;
  char  *map;
} map_t;

typedef struct client {
    int uid;
    int score;
    int client_socket;
    int client_addr_size;
    struct sockaddr_in address;
    size_t ip;
    bool logged;
} client_t;

typedef struct server_s {
    int port;
    int gravity;
    int socket_server;
    int status_server;
    int fd_actual;
    struct protoent *protocol;
    struct sockaddr_in sin;
    fd_set readfds;
    fd_set writefds;
    socklen_t sin_size;
    player_t *players;
    client_t *client;
    map_t *map;
    int ready;
} server_t;


int server_init(int argc, char** argv);
void init_client(server_t *server);
void start_init(server_t *server);


//map.c
int check_maps(const char *filename, server_t *server);
int check_char(const char *buffer);
int put_char(const char *buffer, server_t *server, int height);
void check_size_map(server_t *server);
void init_map(map_t *map);


void client_checking_handler(server_t *server);
void launch_server(server_t *server);
void client_checking_handler(server_t *server);
void client_read_write(server_t *server, int i);
char *read_client_message(int sock);
void client_connection(server_t *server, int i);
void bind_server(server_t *server);
void check_server_error(server_t *server);
int check_args(int argc, char ** argv, server_t *server);
void init_struct_server(server_t *server);
void client_init(server_t *server);

#endif /* !SERVER_H_ */
