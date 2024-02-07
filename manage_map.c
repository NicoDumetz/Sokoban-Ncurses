/*
** EPITECH PROJECT, 2023
** ma,nage map
** File description:
** manage map sokoban
*/

#include "include/my_printf.h"
#include "include/my_sokoban.h"

char **cpy_array(char **dest, char **src, struct player *player)
{
    for (int i = 0; src[i]; i++) {
        for (int j = 0; src[i][j]; j++) {
            dest[i][j] = src[i][j];
        }
    }
    set_player(player, dest);
    return dest;
}

static int verify_x(char **map, int i, int j, struct player *flags)
{
    if (map[i][j] != 'X')
        return 0;
    for (int k = 0; flags[k].x != -1; k++) {
        if (flags[k].x == j && flags[k].y == i)
            return 0;
    }
    if ((map[i + 1][j] == '#' || map[i + 1][j] == 'X') && (map[i][j - 1] ==
    '#' || map[i][j - 1] == 'X'))
        return 1;
    if ((map[i][j - 1] == '#' || map[i][j - 1] == 'X') && (map[i - 1][j] ==
    '#' || map[i - 1][j] == 'X'))
        return 1;
    if ((map[i - 1][j] == '#' || map[i - 1][j] == 'X') && (map[i][j + 1] ==
    '#' || map[i][j + 1] == 'X'))
        return 1;
    if ((map[i][j + 1] == '#' || map[i][j + 1] == 'X') && (map[i + 1][j] ==
    '#' || map[i + 1][j] == 'X'))
        return 1;
}

static int get_nb(char **map)
{
    int nb = 0;

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            nb += map[i][j] == 'X' ? 1 : 0;
        }
    }
    return nb;
}

int loose(char **map, struct player *flags, struct player *player)
{
    int nbr_x = get_nb(map);
    int nbr_case_block = 0;

    for (int i = 0; map[i]; i++) {
        for (int j = 0; map[i][j]; j++) {
            nbr_case_block += verify_x(map, i, j, flags) == 1 ? 1 : 0;
        }
    }
    if (nbr_case_block == nbr_x)
        return 1;
    return 0;
}