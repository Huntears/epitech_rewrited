/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** put_str
*/

#include "sokoban.h"
#include <unistd.h>

void put_str(char const *str)
{
    write(1, str, my_strlen(str));
}