/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** init_lib
*/

#include "sokoban.h"
#include <ncurses.h>

int main_loop(o_link_t *map) {
  display_map(map);
  if (event_handler(map) || is_won(map))
    return (0);
  return (1);
}