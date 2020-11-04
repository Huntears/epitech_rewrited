/*
** EPITECH PROJECT, 2019
** my_strcmp
** File description:
** Compare two strings
*/

/*
 *  Compare two strings
 *  Return 0 if they are identical
 *  Return the diff of the first different
 *  character if they are not identical
 */
int my_strcmp(char const *s1, char const *s2) {
  for (int i = 0; s1[i] || s2[i]; i++)
    if (s1[i] != s2[i])
      return (s1[i] - s2[i]);
  return (0);
}