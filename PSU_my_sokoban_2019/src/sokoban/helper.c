/*
** EPITECH PROJECT, 2019
** PSU_my_sokoban_2019
** File description:
** helper
*/

#include "sokoban.h"

/*
 *  Print the helper of the sokoban project
 */
int helper(void) {
  put_str("USAGE\n"
          "\t./my_sokoban map\n"
          "DESCRIPTION\n"
          "\tmap\tfile representing the warehouse map, "
          "containing '#' for walls,\n"
          "\t\t'P' for the player, 'X' for boxes and 'O' "
          "for storage locations.\n");
  return (0);
}
