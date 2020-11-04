/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019 [WSL: Debian]
** File description:
** is_won
*/

#include <stdlib.h>
#include <stdio.h>
#include "sokoban.h"

static int vec_eq(vector2d_t a, vector2d_t b) {
    if (a.x == b.x && a.y == b.y)
        return (1);
    return (0);
}

static int is_on_landmark(o_link_t *map, o_link_t *original)
{
    vector2d_t box_pos = map->position;

    if (map->display != 'X')
        return (1);
    for (; original; original = original->next)
        if (vec_eq(box_pos, original->position) && original->display == 'O')
            return (1);
    return (0);
}

int is_won(o_link_t *map)
{
    o_link_t *original = map;

    for (; map != NULL; map = map->next) {
        for (; map->display != 'X' && map->next; map = map->next);
        if (!(is_on_landmark(map, original)))
            return (0);
    }
    return (1);
}