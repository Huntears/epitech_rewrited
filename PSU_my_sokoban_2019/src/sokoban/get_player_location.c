/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019 [WSL: Debian]
** File description:
** get_player_location
*/

#include "sokoban.h"

vector2d_t get_player_location(o_link_t *map) {
  return (get_player_node(map)->position);
}
