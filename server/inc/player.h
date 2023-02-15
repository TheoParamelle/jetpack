/*
** EPITECH PROJECT, 2022
** B-SYN-400-LYN-4-1-jetpack2tek3-theo.paramelle
** File description:
** player
*/

#ifndef PLAYER_H_
#define PLAYER_H_

#include "server.h"

typedef struct player_s {
  int   id;
  int   score;
  int   gravity;
  float x;
  float y;
} player_t;

void init_player(player_t *player);


#endif /* !PLAYER_H_ */
