/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** event_handler
*/

#include "sokoban.h"
#include <ncurses.h>

int event_handler(o_link_t *map) {
  switch (getch()) {
  case 32:
    return (1);
  case KEY_UP:
    move_up(map);
    break;
  case KEY_DOWN:
    move_down(map);
    break;
  case KEY_LEFT:
    move_left(map);
    break;
  case KEY_RIGHT:
    move_right(map);
    break;
  }
  return (0);
}
