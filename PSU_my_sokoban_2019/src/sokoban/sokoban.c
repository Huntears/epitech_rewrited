/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** sokoban
*/

#include "sokoban.h"
#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>

static void init_display(void) {
  initscr();
  noecho();
  curs_set(0);
  keypad(stdscr, TRUE);
}

static void destroy_sokoban(o_link_t *map) {
  o_link_t *current = NULL;

  endwin();
  while (map) {
    current = map;
    map = map->next;
    free(current);
  }
}

int sokoban(int argc, char **argv) {
  o_link_t *map = NULL;

  if (argc != 2)
    return (84);
  if (!(my_strcmp(argv[1], "-h")))
    return (helper());
  if (!(map = load_map(argv[1])))
    return (84);
  init_display();
  while (main_loop(map))
    refresh();
  destroy_sokoban(map);
  return (0);
}
