/*
** EPITECH PROJECT, 2023
** deplacement
** File description:
** deplacement of perso
*/

#include "include/my_sokoban.h"
#include "include/my_printf.h"


void left(char **map, struct player *player, struct player *flags)
{
    if (map[player->x][player->y - 1] == 'X' && (map[player->x][player->y -
        2] == ' ' || map[player->x][player->y - 2] == 'O')) {
        map[player->x][player->y - 2] = 'X';
        map[player->x][player->y - 1] = 'P';
        map[player->x][player->y] = ' ';
        player->y -= 1;
        return;
    }
    if (map[player->x][player->y - 1] == ' ' || map[player->x][player->y - 1]
    == 'O') {
        map[player->x][player->y - 1] = 'P';
        map[player->x][player->y] = ' ';
        player->y -= 1;
    }
}

void right(char **map, struct player *player)
{
    if (map[player->x][player->y + 1] == 'X' && (map[player->x][player->y +
        2] == ' ' || map[player->x][player->y + 2] == 'O')) {
        map[player->x][player->y + 2] = 'X';
        map[player->x][player->y + 1] = 'P';
        map[player->x][player->y] = ' ';
        player->y += 1;
        return;
    }
    if (map[player->x][player->y + 1] == ' ' || map[player->x][player->y + 1]
    == 'O') {
        map[player->x][player->y + 1] = 'P';
        map[player->x][player->y] = ' ';
        player->y += 1;
    }
}

void down(char **map, struct player *player)
{
    if (map[player->x + 1][player->y] == 'X' && (map[player->x + 2]
        [player->y] == ' ' || map[player->x + 2][player->y] == 'O')) {
        map[player->x + 2][player->y] = 'X';
        map[player->x + 1][player->y] = 'P';
        map[player->x][player->y] = ' ';
        player->x += 1;
        return;
    }
    if (map[player->x + 1][player->y] == ' ' || map[player->x + 1][player->y]
    == 'O') {
        map[player->x + 1][player->y] = 'P';
        map[player->x][player->y] = ' ';
        player->x += 1;
    }
}

void go_up(char **map, struct player *player)
{
    if (map[player->x - 1][player->y] == 'X' && (map[player->x - 2]
        [player->y] == ' ' || map[player->x - 2][player->y] == 'O')) {
        map[player->x - 2][player->y] = 'X';
        map[player->x - 1][player->y] = 'P';
        map[player->x][player->y] = ' ';
        player->x -= 1;
        return;
    }
    if (map[player->x - 1][player->y] == ' ' || map[player->x - 1][player->y]
    == 'O') {
        map[player->x - 1][player->y] = 'P';
        map[player->x][player->y] = ' ';
        player->x -= 1;
    }
}

int my_strcmp(char const *s1, char const *s2)
{
    int index;

    for (index = 0; s1[index] != '\0' || s2[index] != '\0'; index++) {
        if (s1[index] > s2[index])
            return 1;
        if (s2[index] > s1[index])
            return -1;
    }
    if ( s1[index] == '\0' && s2[index] == '\0')
        return 0;
    if (s1[index] != '\0')
        return -1;
    else
        return 1;
}
