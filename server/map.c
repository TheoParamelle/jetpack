/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle
** File description:
** map
*/

#include "server.h"

void init_map(map_t *map)
{
    map->map = NULL;
    map->width = 0;
    map->height = 0;
}

int check_char(const char *buffer)
{
    for (int i = 0;buffer[i] != '\0'; i++)
        if (buffer[i] != '\n' && buffer[i] != 'c' && buffer[i] != 'e'
        && buffer[i] != '_') {
            printf("Error: invalid  character map\n");
            exit (84);
        }
    return (0);
}

int check_maps(const char *filename, server_t *server)
{
    server->map = malloc(sizeof(map_t));
    init_map(server->map);
    struct stat buf;
    int fd = open(filename, O_RDONLY);
    char *buffer = NULL;
    int file = 0;
    int size = 0;

    stat(filename, &buf);
    size = buf.st_size;
    buffer = malloc(size + 1);
    server->map->map = malloc(size + 1);
    file = read(fd, buffer, size);
    buffer[file] = '\0';

    for (int i = 0, j = 0; buffer[i] != '\0'; i++)  {
        if (buffer[i] == '\n' || buffer[i + 1] == '\0')
            server->map->height++;
        if (buffer[i] != '\n') {
            server->map->map[j] = buffer[i];
            j++;
        }
    }
    for(int i = 0; buffer[i] != '\n'; i++)
        server->map->width++;
    close(fd);
}