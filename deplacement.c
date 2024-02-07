/*
** EPITECH PROJECT, 2023
** deplacement
** File description:
** deplacement of perso
*/

#include "include/my_sokoban.h"

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
