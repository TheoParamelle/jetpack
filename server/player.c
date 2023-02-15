/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle
** File description:
** player
*/

#include "server.h"

void init_player(player_t *player)
{
    player = malloc(sizeof(player_t));
    player->id = 0;
    player->score = 0;
    player->gravity = 0;
    player->x = 0;
    player->y = 0;
}