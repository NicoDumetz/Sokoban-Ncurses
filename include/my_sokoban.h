/*
** EPITECH PROJECT, 2023
** sokoban
** File description:
** header
*/

#ifndef SETTING_UP
    #define SETTING_UP
    #include <unistd.h>
    #include <stdio.h>
    #include <stdarg.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <errno.h>
    #include <stdint.h>
    #include <stddef.h>
    #include <wchar.h>
    #include <sys/stat.h>
    #include <curses.h>
typedef struct player {
    int x;
    int y;
} player;
char **get_map(char **av);
void left(char **map, struct player *player, struct player *flags);
void right(char **map, struct player *player);
void down(char **map, struct player *player);
void go_up(char **map, struct player *player);
void free_array(char **world);
struct player *get_point(char **map, struct player *flags);
int number_point(char **map);
int verify_map(char **map);
#endif
