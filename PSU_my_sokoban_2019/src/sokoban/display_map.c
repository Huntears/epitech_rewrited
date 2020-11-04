/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** display_map
*/

#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>

static vector2d_t get_highest(o_link_t *map) {
  vector2d_t ret = {0, 0};

  for (; map; map = map->next) {
    ret.x = (ret.x < map->position.x) ? map->position.x : ret.x;
    ret.y = (ret.y < map->position.y) ? map->position.y : ret.y;
  }
  return (ret);
}

// TODO : This thing has to be rewritten completely, made me fucking puke
void display_map(o_link_t *map) {
  vector2d_t high = get_highest(map);
  size_t len_buff = (high.y + 1) * (high.x + 1);
  char buff[len_buff];

  clear();
  for (size_t i = 0; i < len_buff; i++)
    buff[i] = 0;
  for (; map; map = map->next)
    if ((!map->priority &&
         !buff[map->position.x + map->position.y * (high.x + 1)]) ||
        map->priority)
      buff[map->position.x + map->position.y * (high.x + 1)] = map->display;
  for (int y = 0; y <= high.y; ++y)
    for (int x = 0; x <= high.x; ++x)
      mvprintw(y, x, "%c", buff[x + y * (high.x + 1)]);
}