/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019 [WSL: Debian]
** File description:
** load_map
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "sokoban.h"

// TODO : Simplify that whole garbage
static void create_node(o_link_t **current, vector2d_t pos, char disp)
{
    o_link_t *new_node = malloc(sizeof(o_link_t));

    new_node->display = disp;
    new_node->position = pos;
    if (disp == 'X' || disp == 'P')
        new_node->priority = 1;
    else
        new_node->priority = 0;
    new_node->next = *current;
    *current = new_node;
    if (new_node->priority == 1)
        create_node(current, pos, ' ');
}

// TODO : Use a bigger buffer for performance sake
static o_link_t *load_nodes(int fd, o_link_t *current)
{
    char buff[1];
    vector2d_t pos = {0, 0};

    while (read(fd, buff, 1)) {
        if (buff[0] == '\n') {
            pos.y++;
            pos.x = 0;
        }
        else {
            create_node(&current, pos, buff[0]);
            pos.x++;
        }
    }
    return (current);
}

/*
*  Load the given map in a linked list
*  with position, priority, and display
*  See -> (struct o_link_s) in sokoban.h
*/
o_link_t *load_map(char *path)
{
    int fd = open(path, O_RDONLY);

    if (fd == -1)
        return (NULL);
    return (load_nodes(fd, NULL));
}